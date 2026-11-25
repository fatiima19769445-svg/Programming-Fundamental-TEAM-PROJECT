#include <iostream>
#include <string>
using namespace std;

void showMenu();
void showDestinations();
void showActivities();
int getValidInput(string message, int minimum, int maximum);
int getBudget();
string getDestinationName(int choice);
string getActivityName(int choice);
int getAccommodationRate(int destination);
int getTransportRate(int destination);
int getFoodRate(int destination);
int getActivityPrice(int activity);
int calculateAccommodation(int travellers, int days, int rate);
int calculateTransport(int travellers, int rate);
int calculateFood(int travellers, int days, int rate);
int selectActivities(int& sightseeing, int& hiking, int& boating, int& museum, int& adventure);
void showTripSummary(int destination, int travellers, int days, int sightseeing, int hiking, int boating, int museum, int adventure, int accommodation, int transport, int food, int activities, int budget);

int main()
{
    int choice;
    do
    {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            showDestinations();
            int destination = getValidInput("Select destination (1-4): ", 1, 4);
            int travellers = getValidInput("Enter number of travellers (1-10): ", 1, 10);
            int days = getValidInput("Enter trip duration in days (1-30): ", 1, 30);
            showActivities();
            int sightseeing = 0, hiking = 0, boating = 0, museum = 0, adventure = 0;
            int activityRate = selectActivities(sightseeing, hiking, boating, museum, adventure);
            int budget = getBudget();
            int accommodationRate = getAccommodationRate(destination);
            int transportRate = getTransportRate(destination);
            int foodRate = getFoodRate(destination);
            int accommodation = calculateAccommodation(travellers, days, accommodationRate);
            int transport = calculateTransport(travellers, transportRate);
            int food = calculateFood(travellers, days, foodRate);
            int activities = travellers * activityRate;
            showTripSummary(destination, travellers, days, sightseeing, hiking, boating, museum, adventure, accommodation, transport, food, activities, budget);
        }
        else if (choice == 2)
        {
            showDestinations();
            cout << "\nReturning to main menu...\n";
        }
        else if (choice == 3)
        {
            cout << "\nGoodbye!\n";
        }
        else
        {
            cout << "\nInvalid choice! Please select again.\n";
        }
    } while (choice != 3);
    return 0;
}

void showMenu()
{
    cout << "\n====================================\n";
    cout << "       SMART TRAVEL PLANNER\n";
    cout << "====================================\n";
    cout << "1. Plan a Trip\n";
    cout << "2. View Available Destinations\n";
    cout << "3. Exit\n";
    cout << "====================================\n";
}

void showDestinations()
{
    cout << "\n========== AVAILABLE DESTINATIONS ==========\n";
    cout << "\n1. Murree\n   Accommodation: PKR 9000\n   Transport: PKR 4000\n   Food: PKR 3000";
    cout << "\n\n2. Hunza\n   Accommodation: PKR 12000\n   Transport: PKR 15000\n   Food: PKR 3000";
    cout << "\n\n3. Swat\n   Accommodation: PKR 8000\n   Transport: PKR 6000\n   Food: PKR 2000";
    cout << "\n\n4. Naran\n   Accommodation: PKR 10000\n   Transport: PKR 8000\n   Food: PKR 2500\n";
}

void showActivities()
{
    cout << "\n========== AVAILABLE ACTIVITIES ==========\n";
    cout << "1. Sightseeing - PKR 600\n";
    cout << "2. Hiking      - PKR 1200\n";
    cout << "3. Boating     - PKR 1100\n";
    cout << "4. Museum      - PKR 350\n";
    cout << "5. Adventure   - PKR 1800\n";
    cout << "\nEnter 1-5 to select an activity.\nEnter 0 to finish activity selection.\n";
}

int getValidInput(string message, int minimum, int maximum)
{
    int value;
 do
    {
        cout << message;
        cin >> value;
        if (value < minimum || value > maximum)
            cout << "Invalid input! Please enter again.\n";
    } while (value < minimum || value > maximum);
    return value;
}

int getBudget()
{
    int budget;
    do
    {
        cout << "\nEnter your budget (PKR): ";
        cin >> budget;
        if (budget <= 0)
            cout << "Invalid budget! Enter an amount greater than 0.\n";
    } while (budget <= 0);
    return budget;
}

string getDestinationName(int choice)
{
    if (choice == 1) return "Murree";
    if (choice == 2) return "Hunza";
    if (choice == 3) return "Swat";
    if (choice == 4) return "Naran";
    return "";
}

string getActivityName(int choice)
{
    if (choice == 1) return "Sightseeing";
    if (choice == 2) return "Hiking";
    if (choice == 3) return "Boating";
    if (choice == 4) return "Museum";
    if (choice == 5) return "Adventure";
    return "";
}

int getAccommodationRate(int destination)
{
    if (destination == 1) return 9000;
    if (destination == 2) return 12000;
    if (destination == 3) return 8000;
    if (destination == 4) return 10000;
    return 0;
}

int getTransportRate(int destination)
{
    if (destination == 1) return 4000;
    if (destination == 2) return 15000;
    if (destination == 3) return 6000;
    if (destination == 4) return 8000;
    return 0;
}

int getFoodRate(int destination)
{
    if (destination == 1) return 3000;
    if (destination == 2) return 3000;
    if (destination == 3) return 2000;
    if (destination == 4) return 2500;
    return 0;
}

int getActivityPrice(int activity)
{
    if (activity == 1) return 600;
    if (activity == 2) return 1200;
    if (activity == 3) return 1100;
    if (activity == 4) return 350;
    if (activity == 5) return 1800;
    return 0;
}

int calculateAccommodation(int travellers, int days, int rate)
{
    int rooms = (travellers + 1) / 2;
    int nights = days - 1;
    return rooms * nights * rate;
}

int calculateTransport(int travellers, int rate)
{
    return travellers * rate;
}

int calculateFood(int travellers, int days, int rate)
{
    return travellers * days * rate;
}

int selectActivities(int& sightseeing, int& hiking, int& boating, int& museum, int& adventure)
{
    int choice;
    int totalPrice = 0;
    do
    {
        cout << "\nSelect activity (0 to finish): ";
        cin >> choice;
        if (choice == 0)
            break;
        if (choice < 1 || choice > 5)
        {
            cout << "Invalid activity! Please select 1 to 5.\n";
            showActivities();
        }
        else
        {
            int alreadySelected = 0;
            if (choice == 1)
            {
                if (sightseeing == 1) alreadySelected = 1;
                else sightseeing = 1;
            }
            if (choice == 2)
            {
                if (hiking == 1) alreadySelected = 1;
                else hiking = 1;
            }
            if (choice == 3)
            {
                if (boating == 1) alreadySelected = 1;
                else boating = 1;
            }
            if (choice == 4)
            {
                if (museum == 1) alreadySelected = 1;
                else museum = 1;
            }
            if (choice == 5)
            {
                if (adventure == 1) alreadySelected = 1;
                else adventure = 1;
            }
            if (alreadySelected == 1)
                cout << "This activity is already selected! Try another.\n";
            else
            {
                totalPrice = totalPrice + getActivityPrice(choice);
                cout << getActivityName(choice) << " added successfully.\n";
            }
        }
    } while (choice != 0);
    return totalPrice;
}

void showTripSummary(int destination, int travellers, int days, int sightseeing, int hiking, int boating, int museum, int adventure, int accommodation, int transport, int food, int activities, int budget)
{
    int total = accommodation + transport + food + activities;
    cout << "\n====================================\n           TRIP SUMMARY\n====================================\n";
    cout << "Destination: " << getDestinationName(destination) << endl;
    cout << "Number of Travellers: " << travellers << endl;
    cout << "Duration: " << days << " days\n";
    cout << "\nSelected Activities:\n";
    if (sightseeing == 0 && hiking == 0 && boating == 0 && museum == 0 && adventure == 0)
        cout << "None\n";
    else
    {
        if (sightseeing == 1) cout << "- Sightseeing\n";
        if (hiking == 1) cout << "- Hiking\n";
        if (boating == 1) cout << "- Boating\n";
        if (museum == 1) cout << "- Museum\n";
        if (adventure == 1) cout << "- Adventure\n";
    }
    cout << "\n========== COST BREAKDOWN ==========\n";
    cout << "Accommodation: PKR " << accommodation << endl;
    cout << "Transport:     PKR " << transport << endl;
    cout << "Food:          PKR " << food << endl;
    cout << "Activities:    PKR " << activities << endl;
    cout << "------------------------------------\n";
    cout << "Total Estimated Cost: PKR " << total << endl;
    cout << "\nEntered Budget: PKR " << budget << endl;
    if (total <= budget)
        cout << "WITHIN BUDGET - remaining PKR " << budget - total << endl;
    else
        cout << "OVER BUDGET - exceeded by PKR " << total - budget << endl;
    cout << "====================================\n";
}