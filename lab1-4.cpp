#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int number;

class People
{
	private:
		int satiety;
	protected:
		int age;
		float month;
		string name;
		int x_position;
		int y_position;
		int speed;
		int health;
	public:	
		People()
		{
			name = "Noname";
			month = 0;
			speed = 3;
			age = number;
			x_position = 0;
			y_position = 0;
			health = 100;
			satiety = 100;
		}; 
		
		void setDate();
		int ask();
		int ages();
		void getDate();
		void getDates();
		void eat();
		void run();
};

class Killer : public People
{
	private:
		int power;
	public:
		Killer () : People() 
		{
			name = "Zombie killer";
			power = 100;
		}
		void getInf();
		void walk();
		void kill();
		void sleep();	
};

void People :: setDate()
{
	cout << "\nEnter name: ";
	cin >> name;
	cout << "\nEnter speed from 1 to 5: ";
	cin >> speed;
}

void People :: getDate()
{
	cout << "\nName is: " << name;
	cout << "\nAge is: " << number << " year and " << month << " month";
	cout << "\nSpeed is: " << speed;
}

void People :: getDates()
{
	cout << "\nHealth is: " << health;
	cout << "\nSatiety is: " << satiety;
	cout << "\nPosition is: (" << x_position << "," << y_position << ")";
}

int People :: ask()
{
	cout << "\nHow old are you?";
	cin >> age;
	return age;
}

int People :: ages()
{
	return age;
}

void People :: eat()
{
	satiety = satiety + 5;
	health = health + 2;
	month = month + 1;
	if (month >= 12)
		{
			age++;
			month = month - 12;
		}
	if (satiety > 100)
		{
			satiety = 100;
		}
	if (health > 100)
		{
			health = 100;
		}
	cout << "\nYou got some food!";
}

void People :: run()
{
	x_position = x_position + speed * rand() % 4;
	y_position = y_position + speed * rand() % 4;
	satiety = satiety - 3;
	health = health - 1;
	cout << "\nYou have just walked!";
	if(x_position - y_position == 2 || y_position - x_position == 2)
		{
			cout << "\nZombie bit you!";
			health = health - 15;
		}
	if (satiety <= 0 || health <= 0)
		{
			cout << "\nYou are dead!";
		}
}

void Killer :: getInf()
{
	cout << "\nPower is: " << power;
	People :: getDates();
}

void Killer :: walk()
{
	power = power - 3;
	People :: run();
}

void Killer :: kill()
{
	if(x_position - y_position == 2 || y_position - x_position == 2)
		{
			cout << "\nYou killed zombie";
			health = health + 7;
			power = power - 10;
		}
	else
		{
			cout << "Try again! You will find some zombie next time!";
			power = power - 5;
		}
}

void Killer :: sleep()
{
	power = power + 7;
	cout << "\nYou have just slept!";
	if (power > 100)
	{
		power = 100;
	}
}

int main()
{
	cout << "\t\tCreating a character...";
	
	Killer Gamer;
	
	number = Gamer.ask();
	if (number < 18)
	{
		cout << "\nYou are very small for killing zombie! Wait some time.";
		People Player;
		Player.getDate();
	
		cout << "\n\tDo you want to change information? (y or n)\n";
		char answer;
		cin >> answer;
		
		while (answer == 'y')
		{
			Player.setDate();
			cout << "\n\tInformation about character:";
			Player.getDate();
			cout << "\n\tDo you want to change information? (y or n)\n";
			cin >> answer;
		}
			
		cout << "\n\t\tDo you want to continue game? (y or n)\n";
		cin >> answer;
		
		if (answer == 'n')
		{
			cout << "\n\t\tThank you for game!";
			exit(1);
		}
		
		while (number < 18 )
		{
			number = Player.ages();
			cout << "\n\t\t\tChoose what you want to do:";
			cout << "\n\t\t1. Eat";
			cout << "\n\t\t2. Run.";
			cout << "\n\t\t3. Check your personal information.";
			cout << "\n\t\t4. Check your state.";
			cout << "\n\t\t5. Finish the game.";
			char reply;
			cin >> reply;
				switch (reply)
				{
					case '1':
						Player.eat();
						break;
					case '2':
						Player.run();
						break;
					case '3':
						Player.getDate();
						break;
					case '4':
						Player.getDates();
						break;
					case '5':
						cout << "\n\t\tThank you for game!";
						exit(1);
				}
			number = Player.ages();
		}
		 
	}
	cout << "\nYou can kill zombie!!";
	Gamer.getDate();
	
	cout << "\n\tDo you want to change information? (y or n)\n";
	char answer;
	cin >> answer;
	while (answer == 'y')
	{
		Gamer.setDate();
		cout << number;
		cout << "\n\tInformation about character:";
		Gamer.getDate();
		cout << "\n\tDo you want to change information? (y or n)\n";
		cin >> answer;
		}
			
		cout << "\n\t\tDo you want to continue game? (y or n)\n";
		cin >> answer;
		
		while (answer == 'y')
		{
			cout << "\n\t\t\tChoose what you want to do:";
			cout << "\n\t\t1. Eat";
			cout << "\n\t\t2. Run.";
			cout << "\n\t\t3. Check your personal information.";
			cout << "\n\t\t4. Check your state.";
			cout << "\n\t\t5. Kill zombie.";
			cout << "\n\t\t6. Sleep.";
			cout << "\n\t\t7. Finish the game.\n";
			char reply;
			cin >> reply;
				switch (reply)
				{
					case '1':
						Gamer.eat();
						break;
					case '2':
						Gamer.walk();
						break;
					case '3':
						Gamer.getDate();
						break;
					case '4':
						Gamer.getInf();
						break;
					case '5':
						Gamer.kill();
						break;
					case '6':
						Gamer.sleep();
						break;
					case '7':
						cout << "\n\t\tThank you for game!";
						exit(1);
						break;
				}
		}

	cout << "\n\t\tThank you for game!";
	return 0;
}
