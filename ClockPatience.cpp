#include <iostream>
#include <string>
using namespace std;

struct Card
{
	char rank;
	char suit;
};

struct Pile
{
	Card cards[4];
	int size;
	Pile()
	{
		size = -1;
	}
};

int main()
{
	string cur_card;
	int index = 0;
	Pile piles[13];
	while (1)
	{
		cin >> cur_card;
		if (cur_card.compare("#") == 0)
		{
			break;
		}
        char rank = cur_card[0];
		char suit = cur_card[1];
		Card card = {rank, suit};
		int pile_index = (51-index) % 13; 
		int card_index = 3 - index/13;
		piles[pile_index].cards[card_index] = card;
		piles[pile_index].size += 1;
		index++;
		if (index == 52)
		{
			//for (int i=3; i>=0; i--)
			//{
			//	for (int j=0; j<=12; j++)
			//	{
			//		cout << piles[j].cards[i].rank << piles[j].cards[i].suit << " ";
			//	}
			//	cout << endl;
			//}
			index = 0;
			Card exposed = piles[12].cards[3];
			piles[12].size -= 1;
			int exposed_num = 1;
			int next_pile = 0;
			while (1)
			{
				//cout << exposed.rank << exposed.suit << endl;
				switch (exposed.rank)
				{
				case 'A':
					next_pile = 0;
					break;
				case 'T':
					next_pile = 9;
					break;
				case 'J':
					next_pile = 10;
					break;
				case 'Q':
					next_pile = 11;
					break;
				case 'K':
					next_pile = 12;
					break;
				default:
					next_pile = (int)(exposed.rank-'0') - 1;
					break;
				}
				int top = piles[next_pile].size;
				if (top == -1)
				{
					break;
				}
				exposed_num++;
				exposed = piles[next_pile].cards[top];
				piles[next_pile].size -= 1;
			}
			if (exposed_num < 10)
			{
				cout << "0" << exposed_num << "," << exposed.rank << exposed.suit << endl;
			}
			else
			{
				cout << exposed_num << "," << exposed.rank << exposed.suit << endl;
			}
			
			for (int i=0; i<=12; i++)
			{
				piles[i].size = -1;
			}
		}
	}

	
    
	return 0;
}