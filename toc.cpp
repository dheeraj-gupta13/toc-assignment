#include <bits/stdc++.h>
using namespace std;

#define ll long long

int f(string user, unordered_map<string, ll> &balance, vector<string> &logs)
{

    cout << "\n";
    cout << "*****************\n";
    cout << "Choose 1 to check balance. \n";
    cout << "Choose 2 to withdraw. \n";
    cout << "Choose 3 to deposit. \n";
    cout << "Choose 4 to transfer amount to other bank. \n";
    cout << "Choose 5 to check your logs. \n";
    cout << "Choose 6 to exit. \n";
    cout << "*****************\n";
    cout << "\n";

    int choice;
    cin >> choice;

    if (choice == 6)
    {
        cout << "Thank you for using our service, " << user << endl;
        return 1;
    }

    if (choice == 1)
    {
        cout << "Your balance is : " << balance[user] << endl;
        logs.push_back("Balance Checked");
    }
    else if (choice == 2)
    {
        cout << "Enter the amount to withdraw : ";
        int amount;
        cin >> amount;
        if (amount > balance[user])
        {
            cout << "Insufficient Balance" << endl;
        }
        else
        {
            balance[user] -= amount;
            cout << "Please collect your cash" << endl;

            logs.push_back("Amount Withdrawn");
        }
    }
    else if (choice == 3)
    {
        cout << "Enter the amount to deposit : ";
        int amount;
        cin >> amount;
        balance[user] += amount;
        cout << "Your balance is : " << balance[user] << endl;

        logs.push_back("Amount Deposited");
    }
    else if (choice == 4)
    {
        cout << "Please Enter the name of the user you want to transfer: ";
        string o;
        cin >> o;

        cout << "Please Enter the amount you want to transfer: ";
        int amt;
        cin >> amt;

        if (amt > balance[user])
        {
            cout << "Insufficient Balance" << endl;
        }
        else if (balance.find(o) == balance.end())
        {
            cout << "User not found" << endl;
        }
        else
        {
            balance[user] -= amt;
            balance[o] += amt;

            cout << "Amount Transferred Successfully" << endl;
            cout << "Your balance is : " << balance[user] << endl;
            cout << o << " balance is : " << balance[o] << endl;

            string transfer = "Rs. " + to_string(amt) + " transferred to " + o;
            logs.push_back(transfer);
        }
    }
    else if (choice == 5)
    {
        cout << "Your Logs are : " << endl;

        if (logs.size() == 0)
        {
            cout << "No Logs Found" << endl;
        }
        else
        {

            for (auto x : logs)
            {
                cout << x << endl;
            }
        }
    }
    else
    {
        cout << "Invalid Input" << endl;
    }

    return 0;
}

void init(unordered_map<ll, string> &mp, unordered_map<string, ll> &balance)
{
    cout << "Please Enter the pin : ";
    int pin;
    cin >> pin;

    if (mp.find(pin) != mp.end())
    {
        cout << "Welcome, " << mp[pin] << endl;

        vector<string> logs;
        while (1)
        {
            int val = f(mp[pin], balance, logs);
            if (val == 1)
            {
                break;
            }
        }
    }
    else
    {
        cout << "Invalid Pin" << endl;
    }
}

int main()
{

    cout << "************** BANK **************\n";
    unordered_map<ll, string> mp;
    mp[1234] = "Gorakh";
    mp[3218] = "Dheeraj";
    mp[5982] = "Atharva";
    mp[8152] = "Gunjeet";

    unordered_map<string, ll> balance;
    balance["Gorakh"] = 1000;
    balance["Dheeraj"] = 1000;
    balance["Atharva"] = 1000;
    balance["Gunjeet"] = 1000;

    init(mp, balance);
    return 0;
}