#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct User {
    int accountNumber;
    char name[100];
    char password[100];
    int age;
    char sex[10];
    float accountBalance;
};

void loginAccount(struct User user) {
    int accountNumber;
    char password[100];

    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);
    printf("Enter Password: ");
    scanf("%s", password);

    if (accountNumber == user.accountNumber && strcmp(password, user.password) == 0) {
        printf("Login Successful!\n");
    } else {
        printf("Invalid Account Number or Password!\n");
    }
}

void checkAccount(struct User user) {
    printf("Account Number: %d\n", user.accountNumber);
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Sex: %s\n", user.sex);
    printf("Account Balance: %.2f VND\n", user.accountBalance);
}

void withdrawal(struct User *user) {
    float amount;

    printf("Enter Amount to Withdraw (must be a multiple of 10,000 VND): ");
    scanf("%f", &amount);

    if (amount >= 50000 && fmod(amount, 10000) == 0) {
        if (amount <= user->accountBalance) {
            user->accountBalance -= amount;
            printf("Withdrawal Successful!\n");
        } else {
            printf("Insufficient Account Balance!\n");
        }
    } else {
        printf("Invalid Withdrawal Amount!\n");
    }
}

void sendCash(struct User *user) {
    int receiverAccountNumber;
    float amount;

    printf("Enter Receiver's Account Number: ");
    scanf("%d", &receiverAccountNumber);
    printf("Enter Amount to Send: ");
    scanf("%f", &amount);

    if (amount >= 50000) {
        if (amount <= user->accountBalance) {
            user->accountBalance -= amount;
            printf("Cash Sent Successfully!\n");
        } else {
            printf("Insufficient Account Balance!\n");
        }
    } else {
        printf("Invalid Amount to Send!\n");
    }
}

void updateAccount(struct User *user) {
    int choice;

    printf("1. Add Funds\n");
    printf("2. Remove Funds\n");
    printf("3. Change Account Information\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            float amount;
            printf("Enter Amount to Add: ");
            scanf("%f", &amount);
            user->accountBalance += amount;
            printf("Funds Added Successfully!\n");
            break;
        case 2:
            float removalAmount;
            printf("Enter Amount to Remove: ");
            scanf("%f", &removalAmount);
            if (removalAmount <= user->accountBalance) {
                user->accountBalance -= removalAmount;
                printf("Funds Removed Successfully!\n");
            } else {
                printf("Insufficient Account Balance!\n");
            }
            break;
        case 3:
            printf("Enter New Name: ");
            scanf("%s", user->name);
            printf("Enter New Password: ");
            scanf("%s", user->password);
            printf("Account Information Updated Successfully!\n");
            break;
        default:
            printf("Invalid Choice!\n");
            break;
    }
}

int main() {
    struct User user = {123456, "John Doe", "password", 30, "Male", 5000000.0};
    int choice;

    do {
        printf("\n--- ATM Menu ---\n");
        printf("1. Login Account\n");
        printf("2. Check Account\n");
        printf("3. Withdrawal\n");
        printf("4. Send Cash\n");
        printf("5. Update Account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loginAccount(user);
                break;
            case 2:
                checkAccount(user);
                break;
            case 3:
                withdrawal(&user);
                break;
            case 4:
                sendCash(&user);
                break;
            case 5:
                updateAccount(&user);
                break;
            case 6:
                printf("Exiting ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
