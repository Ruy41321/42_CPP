#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	(void)src;
	return *this;
}

PmergeMe::~PmergeMe() {}

std::string PmergeMe::VectorToStr(const std::vector<int> &vec) {
    std::ostringstream oss;
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        oss << *it << " ";
    }
    return oss.str();
}

std::string PmergeMe::ListToStr(const std::list<int> &lst) {
    std::ostringstream oss;
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        oss << *it << " ";
    }
    return oss.str();
}

struct Pair {
    int maxv;
    int minv;
};

//Funzione di confronto per l'ordinamento delle coppie
struct PairCompare {
	bool operator()(const Pair& a, const Pair& b) const {
	  return a.maxv < b.maxv;
	}
};

// Splitta la lista mettendo ogni 2 numeri il maggiore in A e il minore in B
void pairAndSplit(const std::vector<int>& X, std::vector<int>& A, std::vector<int>& B)
{
    int n = X.size();
    int pairCount = n / 2;
    A.reserve(pairCount);
    B.reserve(pairCount + (n % 2));

    for (int i = 0; i < pairCount; ++i) {
        const int& v1 = X[2*i];
        const int& v2 = X[2*i + 1];
        if (v1 < v2) {
            A.push_back(v2);
            B.push_back(v1);
        } else {
            A.push_back(v1);
            B.push_back(v2);
        }
    }
    if (n % 2 == 1) {
        B.push_back(X[n-1]);
    }
}

// Restituisce un insieme contentente il numero di elementi da inserire nella insieme finale divisi in gruppi
// se abbiamo 5 elementi restituira (2, 3) cio indica che il primo gruppo avra 2 elementi e il secondo 3
std::vector<int> computeGroupSizes(int k)
{
    std::vector<int> sizes;
    if (k <= 0) return sizes;

    // primi due gruppi = 2,2
    sizes.reserve(10);
    sizes.push_back(2);
    sizes.push_back(2);

    int total = 4;
    for (int i = 2; total < k; ++i) {
        int next = (1 << (i + 1)) - sizes[i-1];
        sizes.push_back(next);

        total = 0;
        for (int j = 0; j < int(sizes.size()); ++j) {
            total += sizes[j];
        }
    }
    // tronca l’ultimo se eccede k
    int sum = 0;
    for (int i = 0; i < int(sizes.size()); ++i) {
        if (sum + sizes[i] > k) {
            sizes[i] = k - sum;
        }
        sum += sizes[i];
    }
    // rimuove zeri finali
    while (!sizes.empty() && sizes.back() == 0) {
        sizes.pop_back();
    }
    return sizes;
}

// In base alla dimensione dei gruppi restiutisce un ordine di inserimento
// in modo da ottimizzare il numero di confronti quando si inseriscono
std::vector<int> computeInsertionOrder(const std::vector<int>& groupSizes)
{
    std::vector<int> order;
    order.reserve(50);
    int offset = 1;  // primo minore già in testa
    for (int i = 0; i < int(groupSizes.size()); ++i) {
        int sz = groupSizes[i];
        for (int j = offset + sz - 1; j >= offset; --j) {
            order.push_back(j);
        }
        offset += sz;
    }
    return order;
}

// Restituisce la posizione in cui inserire il numero 'value' in S ottimizzando il numero di confronti
// higher sarà l'indice in S del maggiore della coppia quindi è inutile confronare oltre questo numero e i confronti partono
// dall'indice medio tra higher e 0
int binaryInsertPos(const std::vector<int>& S, const int& value, int higher)
{
    int lower = 0;
    while (lower < higher) {
        int mid = lower + (higher - lower) / 2;
        if (value < S[mid]) {
            higher = mid;
        } else {
            lower = mid + 1;
        }
    }
    return lower;
}

// Inserisci i minori rimanenti in S usando l'ordine calcolato
void insertRemaining(std::vector<int>& S, const std::vector<int>& Y, const std::vector<int>& order)
{
    for (int i = 0; i < int(order.size()); ++i) {
        int idx = order[i];
        int pos = binaryInsertPos(S, Y[idx], idx + i + 1);
        S.insert(S.begin() + pos, Y[idx]);
    }
}

// Algoritmo principale per rioridino un vettore
void PmergeMe::mergeInsertSortVector(std::vector<int>& X)
{
	// Crea le coppie formate da un numero in A (insieme dei maggiori) e uno in B (insieme dei minori)
	// e pusha la coppia nell insieme delle coppie
    std::vector<Pair> pairs;
    std::vector<int> A, B;
    pairAndSplit(X, A, B); 
    pairs.reserve(A.size());
    for (int i = 0; i < int(A.size()); ++i) {
        Pair p;
        p.maxv = A[i];
        p.minv = B[i];
        pairs.push_back(p);
    }
	// Ordina l'insieme delle coppie in base al valore del numero maggiore
    std::sort(pairs.begin(), pairs.end(), PairCompare());

    // Pusha nell'insieme S I numeri maggiori (ordinati) e il primo numero minore
	// invece in Y i numeri minori
    std::vector<int> Y;
    std::vector<int> S;
    Y.reserve(B.size());
	S.reserve(X.size());
	for (int i = 0; i < int(pairs.size()); ++i) {
		Y.push_back(pairs[i].minv);
		S.push_back(pairs[i].maxv);
	}
    if (B.size() > A.size()) {
        Y.insert(Y.begin(), B.back());
		S.insert(S.begin() + binaryInsertPos(S, Y[0], int(S.size())), Y[0]);
    }
	else
		S.insert(S.begin(), Y[0]);

    // Calcola l ordine di inserimento dei minori in base alla dimensione dei gruppi 
    std::vector<int> groups = computeGroupSizes(int(Y.size()) - 1);
    std::vector<int> order  = computeInsertionOrder(groups);

    // Inserisce i minori rimanenti, in S, usando l'ordine calcolato e un metodo di
	// inserimento che fa in modo da ottimizzare il numero di confronti basandosi sulla posizione
	// del numero maggiore collegato alla coppia del minore
    insertRemaining(S, Y, order);

    // riassegna a X l'insieme ordinato S
    X = S;
}

// Prende l'n-esimo elemento da una lista
int getNth(const std::list<int>& L, int n) {
    assert(n >= 0 && n <= (int)L.size());
    std::list<int>::const_iterator it = L.begin();
    for (int i = 0; i < n; ++i) ++it;
    return *it;
}

std::list<int>::iterator getNthIterator(std::list<int>& L, int n) {
	assert(n >= 0 && n <= (int)L.size());
	std::list<int>::iterator it = L.begin();
	for (int i = 0; i < n; ++i) ++it;
	return it;
}

// Splitta la lista mettendo ogni 2 numeri il maggiore in A e il minore in B
void pairAndSplitForList(const std::list<int>& X, std::list<int>& A, std::list<int>& B)
{
    std::list<int>::const_iterator it = X.begin();
    while (it != X.end()) {
        int v1 = *it;
        ++it;
        if (it != X.end()) {
            int v2 = *it;
            ++it;
            if (v1 < v2) { A.push_back(v2);  B.push_back(v1); }
            else { A.push_back(v1);  B.push_back(v2); }
        } else {
            B.push_back(v1);
        }
    }
}

// Restituisce la posizione in cui inserire il numero 'value' in S ottimizzando il numero di confronti
// higher sarà l'indice in S del maggiore della coppia quindi è inutile confronare oltre questo numero e i confronti partono
// dall'indice medio tra higher e 0
int binaryInsertPosForList(std::list<int>& S, int value, int higher)
{
	int lower = 0;
	while (lower < higher) {
		int mid = lower + (higher - lower) / 2;
		if (value < getNth(S, mid)) {
			higher = mid;
		} else {
			lower = mid + 1;
		}
	}
	return lower;
}

// Restituisce un inssieme contentente il numero di elementi da inserire nella insieme finale divisi in gruppi
// se abbiamo 5 elementi restituira (2, 3) cio indica che il primo gruppo avra 2 elementi e il secondo 3
std::list<int> computeGroupSizesForList(int k)
{
    std::list<int> sizes;

    if (k <= 0) return sizes;
    sizes.push_back(2);
    sizes.push_back(2);
    int total = 4;
    int i = 2;
    while (total < k) {
        int prev = sizes.back();
        int next = (1 << (i + 1)) - prev;
        sizes.push_back(next);
        total = 0;
        for (std::list<int>::const_iterator it = sizes.begin(); it != sizes.end(); ++it)
            total += *it;
        ++i;
    }
    // tronca ultimo se eccede k
    int sum = 0;
    for (std::list<int>::iterator it = sizes.begin(); it != sizes.end(); ++it) {
        int val = *it;
        if (sum + val > k) {
            *it = k - sum;
        }
        sum += val;
    }
    // rimuove eventuali zeri alla fine
    while (!sizes.empty() && sizes.back() == 0)
        sizes.pop_back();
    return sizes;
}

// In base alla dimensione dei gruppi restiutisce un ordine di inserimento
// in modo da ottimizzare il numero di confronti quando si inseriscono
std::list<int> computeInsertionOrderForList(const std::list<int>& groupSizes)
{
    std::list<int> order;
    int offset = 1;
    for (std::list<int>::const_iterator it = groupSizes.begin(); it != groupSizes.end(); ++it)
    {
        int sz = *it;
        for (int j = offset + sz - 1; j >= offset; --j)
            order.push_back(j);
        offset += sz;
    }
    return order;
}

// Inserisci i minori rimanenti in S usando l'ordine calcolato
void insertRemainingForList(std::list<int>& S, const std::list<int>& Y, const std::list<int>& order)
{
	int i = 0;
    for (std::list<int>::const_iterator it = order.begin(); it != order.end(); ++it)
    {
        int idx = *it;
        int value = getNth(Y, idx);
        int pos = binaryInsertPosForList(S, value, idx + i + 1);
		std::list<int>::iterator itS = getNthIterator(S, pos);
        S.insert(itS, value);
		i++;
    }
}

// Algoritmo principale per rioridinare una lista
void PmergeMe::mergeInsertSortList(std::list<int>& X)
{
	// Crea le coppie formate da un numero in A (insieme dei maggiori) e uno in B (insieme dei minori)
	// e pusha la coppia nell insieme delle coppie
    std::list<Pair> pairs;
    std::list<int> A, B;
    pairAndSplitForList(X, A, B);
    std::list<int>::const_iterator itA = A.begin();
    std::list<int>::const_iterator itB = B.begin();
    while (itA != A.end() && itB != B.end()) {
        Pair p;
        p.maxv = *itA;
        p.minv = *itB;
        pairs.push_back(p);
        ++itA; ++itB;
    }

	// Ordina l'insieme delle coppie in base al valore del numero maggiore
    pairs.sort(PairCompare());

    // Pusha nell'insieme S I numeri maggiori (ordinati) e il primo numero minore
	// invece in Y i numeri minori
    std::list<int> Y;
	std::list<int> S;
    for (std::list<Pair>::const_iterator it = pairs.begin(); it != pairs.end(); ++it){
        Y.push_back(it->minv);
		S.push_back(it->maxv);
    }
    if (B.size() > A.size()) {
        Y.push_front(*itB);
        S.insert(getNthIterator(S, binaryInsertPosForList(S, Y.front(), S.size())), Y.front());
    }
	else
		S.push_front(Y.front());


    // Calcola l ordine di inserimento in base alla dimensione dei gruppi 
    int k = Y.size() - 1;
    std::list<int> groups = computeGroupSizesForList(k);
    std::list<int> order  = computeInsertionOrderForList(groups);

    // Inserisce i minori rimanenti, in S, usando l'ordine calcolato e un metodo di
	// inserimento che fa in modo da ottimizzare il numero di confronti basandosi sulla posizione
	// del numero maggiore collegato alla coppia del minore
    insertRemainingForList(S, Y, order);

    // riassegna X con l insieme ordinato S
    X = S;
}