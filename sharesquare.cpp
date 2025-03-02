#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class ShareSqaure
{
private:
    unordered_map<string, unordered_map<string, double>> balances;
    const string fileName = "balances.txt";

    void saveToFile()
    {
        ofstream file(fileName);
        if (!file)
        {
            cerr << "Error saving data to the file" << endl;
            return;
        }

        for (const auto &user : balances)
        {
            for (const auto &balance : user.second)
            {
                if (balance.second != 0)
                {
                    if (balance.second != 0)
                    {
                        file << user.first << " " << balance.first << " " << balance.second << endl;
                    }
                }
            }
        }

        file.close();
    }

    void loadFromFile()
    {
        ifstream file(fileName);
        if (!file)
        {
            return;
        }
        string user, participant;
        double amount;
        while (file >> user >> participant >> amount)
        {
            balances[user][participant] = amount;
        }

        file.close();
    }

public:
    ShareSqaure()
    {
        loadFromFile();
    }

    ~ShareSqaure()
    {
        saveToFile();
    }

    void addExpense(const string &paidBy, double amount, const vector<string> &participants)
    {
        int numParticipants = participants.size();
        double splitAmount = amount / numParticipants;

        for (const string &participant : participants)
        {
            if (participant != paidBy)
            {
                balances[paidBy][participant] += splitAmount;
                balances[participant][paidBy] -= splitAmount;
            }
        }
        saveToFile();
    }

    void showBalances()
    {
        bool noBalances = true;
        for (const auto &user : balances)
        {
            for (const auto &balance : user.second)
            {
                if (balance.second != 0)
                {
                    noBalances = false;
                    cout << user.first << " owes " << balance.first << ": " << fixed << setprecision(2) << balance.second << endl;
                }
            }
        }
        if (noBalances)
        {
            cout << "No balances to show!" << endl;
        }
    }

    void showUserBalance(const string &user)
    {
        bool noBalance = true;
        if (balances.find(user) != balances.end())
        {
            for (const auto &balance : balances[user])
            {
                if (balance.second != 0)
                {
                    noBalance = false;
                    cout << user << " owes " << balance.first << ": " << fixed << setprecision(2) << balance.second << endl;
                }
            }
        }

        for (const auto &payer : balances)
        {
            if (payer.second.find(user) != payer.second.end() && payer.second.at(user) != 0)
            {
                noBalance = false;
                cout << user << " is owed by " << payer.first << ": " << fixed << setprecision(2) << -(payer.second.at(user)) << endl;
            }
        }

        if (noBalance)
        {
            cout << "No balances for " << user << "!" << endl;
        }
    }
};

int main()
{
    ShareSqaure sharesquare;
    int choice;

    do
    {
        cout << "\n===== ShareSquare Menu =====\n";
        cout << "1. Add Expense\n";
        cout << "2. Show All Balances\n";
        cout << "3. Show User Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string paidBy;
            double amount;
            int numParticipants;
            vector<string> participants;

            cout << "Enter the name of the person who paid: ";
            cin >> paidBy;
            cout << "Enter the amount: ";
            cin >> amount;
            cout << "Enter the number of participants: ";
            cin >> numParticipants;

            participants.resize(numParticipants);
            cout << "Enter the names of participants: \n";
            for (int i = 0; i < numParticipants; ++i)
            {
                cin >> participants[i];
            }

            sharesquare.addExpense(paidBy, amount, participants);
            cout << "Expense added successfully!\n";
            break;
        }

        case 2:
            sharesquare.showBalances();
            break;

        case 3:
        {
            string user;
            cout << "Enter the name of the user: ";
            cin >> user;
            sharesquare.showUserBalance(user);
            break;
        }

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            return 0;
        }
    } while (choice != 4);

    return 0;
}