#include <iostream>
#include "Playlist.h"
using namespace std;

int readInt()
{
	int x;
	while (!(cin >> x))
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid number, try again: ";
	}
	cin.ignore(10000, '\n');
	return x;
}

int main()
{
	Playlist pl;
	int choice = 0;

	while (true)
	{
		cout << "\n=== Music Playlist Manager ===\n";
		cout <<
			"1. Add song to end\n2. Add song to beginning\n3. Add song at position\n4. Remove song by id\n5. Remove song at position\n6. Find song by id\n7. Find song by title\n8. Move song up\n9. Move song down\n10. Display playlist\n11. Play all\n12. Play from position\n13. Clear playlist\n14. Exit\nChoose: ";
		choice = readInt();

		if (choice == 1)
		{
			cout << "ID: ";
			int id = readInt();
			cout << "Title: ";
			string t;
			getline(cin, t);
			cout << "Artist: ";
			string a;
			getline(cin, a);
			cout << "Duration (seconds): ";
			int d = readInt();
			pl.addSongEnd(id, t, a, d);
		}
		else if (choice == 2)
		{
			cout << "ID: ";
			int id = readInt();
			cout << "Title: ";
			string t;
			getline(cin, t);
			cout << "Artist: ";
			string a;
			getline(cin, a);
			cout << "Duration (seconds): ";
			int d = readInt();
			pl.addSongBeginning(id, t, a, d);
		}
		else if (choice == 3)
		{
			cout << "Position: ";
			int pos = readInt();
			cout << "ID: ";
			int id = readInt();
			cout << "Title: ";
			string t;
			getline(cin, t);
			cout << "Artist: ";
			string a;
			getline(cin, a);
			cout << "Duration (seconds): ";
			int d = readInt();
			pl.addSongAt(id, t, a, d, pos);
		}
		else if (choice == 4)
		{
			cout << (pl.removeSongById(readInt())? "Removed.\n" : "Not found.\n");
		}
		else if (choice == 5)
		{
			cout << (pl.removeSongAt(readInt())? "Removed.\n" : "Invalid position.\n");
		}
		else if (choice == 6)
		{
			int pos = pl.findSongById(readInt());
			cout << (pos == -1 ? "Not found.\n" : "Found at position " + to_string(pos) + ".\n");
		}
		else if (choice == 7)
		{
			string t;
			getline(cin, t);
			int pos = pl.findSongByTitle(t);
			cout << (pos == -1 ? "Not found.\n" : "Found at position " + to_string(pos) + ".\n");
		}
		else if (choice == 8)
		{
			cout << (pl.moveSongUp(readInt())? "Moved up.\n" : "Cannot move up.\n");
		}
		else if (choice == 9)
		{
			cout << (pl.moveSongDown(readInt())? "Moved down.\n" : "Cannot move down.\n");
		}
		else if (choice == 10)
			pl.display();
		else if (choice == 11)
			pl.playAll();
		else if (choice == 12)
			pl.playFrom(readInt());
		else if (choice == 13)
		{
			pl.clear();
			cout << "Cleared.\n";
		}
		else if (choice == 14)
			break;
		else
			cout << "Invalid choice.\n";
	}

	return 0;
}
