# ShareSquare

Welcome to ShareSquare, a C++ application that simplifies expense sharing among friends and groups. ShareSquare allows users to split expenses, track balances, and maintain financial transparency with ease.

### Features
1. Add Expenses: Record expenses paid by a user and split them equally among participants.
2. Show Balances: View all outstanding balances between users.
3. User-Specific Balances: Check balances for a specific user.
4. Data Persistence: Balances are saved to a file and automatically loaded on the next run.

### Getting Started
Follow these steps to get ShareSquare running on your local machine.

#### Prerequisites
- A C++ compiler (e.g., g++ for GCC)

#### Installation
1. Clone the repository:
```bash
git clone https://github.com/pulkitgarg04/sharesquare.git
```

2. Navigate to the project directory:
```bash
cd sharesquare
```

#### Running the Application
1. Compile the source code:
    ```bash
    g++ sharesquare.cpp -o sharesquare
    ```

2. Run the program:
```bash
./sharesquare
```

### Usage
Upon running the application, you will see the main menu:
1. Add Expense:
- Enter the name of the person who paid.
- Enter the total amount paid.
- Specify the number of participants and their names.

2. Show All Balances:
- Displays outstanding balances between all users.

3. Show User Balance:
- Enter a user's name to view their individual balance.

4. Exit:
- Exits the application and saves the balances to a file.

### Example
```
=== Splitwise Menu ===
1. Add Expense
2. Show All Balances
3. Show User Balance
4. Exit
Enter your choice: 1
Enter the name of the person who paid: Pulkit
Enter the amount: 100
Enter the number of participants: 3
Enter the names of participants:
Pulkit
Aryan
Ishan
Expense added successfully!
```

### File Storage
Balances are stored in a file named `balances.txt`. This file is updated automatically when you add an expense or exit the program. It is also loaded automatically when the program starts.

### Contribution
Feel free to fork the repository and submit pull requests to enhance the functionality of the script.

#### Steps to Contribute
1. Fork the Repository:
    - Click the Fork button at the top right of the repository page to create a copy of the repository in your GitHub account.

2. Clone Your Fork:
    - Clone your forked repository to your local machine:

    ```bash
    git clone https://github.com/pulkitgarg04/sharesquare.git
    cd sharesquare
    ```

3. Create a New Branch:
    - Create a new branch for your changes:
    ```bash
    git checkout -b feature/your-feature-name
    ```

4. Make Your Changes:
    - Edit the script or add new features. Make sure your changes are well-tested.

5. Commit Your Changes:
    - After making changes, commit them with a clear and descriptive message:
    ```bash
    git add .
    git commit -m "Add a detailed description of your changes"
    ```

6. Push Your Changes:
- Push the changes to your forked repository:
    ```bash
    git push origin feature/your-feature-name
    ```

7. Open a Pull Request (PR):
- Go to the original repository on GitHub.
- Click on the Pull Requests tab.
- Click New Pull Request and choose your branch from your fork as the source.
- Provide a descriptive title and explanation of your changes.

### License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.