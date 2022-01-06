// main.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <ctime>
using namespace std;




int main()
{
	short unsigned lives;
	short unsigned index;
	short unsigned num;
	string easy_words[4] = { "rat", "cat", "dog", "bat" };
	string normal_words[4] = { "mouse", "horse", "rabbit", "dragon" };
	string hard_words[4] = { "alligator", "anglerfish", "caterpillar", "mosquito" };
	string difficult;
	string word;
	char guess;
	srand(time(NULL));
	cout << "What difficult level do you want choose? type 'easy', 'normal' or 'hard'" << endl;
	cin >> difficult;
	if (difficult == "easy")
	{
		lives = 5;
		index = rand() % sizeof(easy_words)/sizeof(easy_words[0]);
		word = easy_words[index];
	}
	else if(difficult == "normal")
	{
		lives = 4;
		index = rand() % sizeof(normal_words) / sizeof(normal_words[0]);
		word = normal_words[index];
	}
	else
	{
		lives = 3;
		index = rand() % sizeof(hard_words) / sizeof(hard_words[0]);
		word = hard_words[index];
	}
	string underscore = string(word.size(), '_');
	while (lives)
	{
		num = 0;
		cout << "Your lives: " << lives << endl;
		cout << "Word: " << underscore << endl;
		cout << "What's your guess?" << endl;
		cin >> guess;
		for (short unsigned i = 0; i <= word.size(); i++)
		{
			if (word[i] == guess)
			{
				underscore[i] = guess;
				num += 1;
			}
			if (word == underscore)
			{
				cout << "You win " << word << " is correct answer." << endl;;
				exit(0);
			}
		}
		if (num == 0)
		{
			lives -= 1;
		}
	}
	cout << "You lose " << word << " is correct answer." << endl;
	return 0;
}