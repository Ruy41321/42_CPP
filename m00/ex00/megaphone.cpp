#include <iostream>

class	Megaphone
{
	public:
		void	play(std::string str);
};

void	Megaphone::play(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		std::cout << (char)toupper(str[i]);
}

int	main(int argc, char **argv)
{
	Megaphone megaphone;

	if (argc == 1)
		megaphone.play("loud and unbearable FeeDBack nOISe");
    else
    {
		for (int i = 1; i < argc; i += 1)
		{
			megaphone.play(argv[i]);
			if (i+1 < argc)
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
	return 0;
}
