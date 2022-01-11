#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int runBinaryToDecial(void) {
    int result;
    char binary[73];
    bool status = true;
    
    printf("===============================\n");
    printf("***          No space allowed       ***\n");
    printf("*** Max number of binary number: 20 ***\n");
    printf("*** Max number of binary points: 52 ***\n");
    printf("Enter binary: ");
    scanf("%s", binary);
    
    
    bool positive = true;
    int positive_arr[20], negative_arr[52];
    
    for (int i = 0; i < 73; i++) {
        if (binary[i] != '0' && binary[i] != '1' && binary[i] != '.') {
            status = false;
            break;
        }
        
        if (binary[i] == '.') {
            positive = false;
        }
    }
    
    if (!status) {
        printf("You entered invalid binary!!\n");
        result = 0;
    }
    
    return 0;
}

int runDecialToBinary(void) {
    return 0;
}

int setMainMenu(void) {
    int result;
    int num;
        
    printf("######## Binary Calculator ########\n");
    printf("[1] Binary to Decimal\n");
    printf("[2] Decimal to Binary\n");
    printf("[0] Exit\n");
    printf("-------------------------------\n");
    printf("Enter option: ");
    scanf("%d", &result);
    
    switch (result) {
        case 1:
            num = runBinaryToDecial();
            return num;
            
        case 2:
            num = runDecialToBinary();
            return num;
            
        case 0:
            return 0;
            break;
            
        default:
            printf("\n");
            printf("!warning! You entered invalid option\n");
            printf("!warning! Please enter valid option\n");
            printf("\n");
            
            int temp_result = setMainMenu();
            return temp_result;
    }
}

int main(void) {
    setMainMenu();
    
    return 0;
}
