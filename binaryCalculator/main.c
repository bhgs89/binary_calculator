#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int runBinaryToDecial(void) {
    int result = 1;
    char binary[118];
    bool status = true;
    int error_no = 0;
    
    printf("===============================\n");
    printf("***          No space allowed       ***\n");
    printf("*** Max number of binary number: 64 ***\n");
    printf("*** Max number of binary points: 52 ***\n");
    printf("Enter binary: ");
    scanf("%s", binary);
    
    bool positive = true;
    int pos_idx = 0;
    int neg_idx = 0;
    int positive_arr[64], negative_arr[52];
    int count_points = 0;
    
    for (int i = 0; i < 118; i++) {
        if (binary[i] == '.') {
            count_points++;
        }
        
        if (count_points >= 2) {
            status = false;            
            break;
        }
        
        if (binary[i] != '0' && binary[i] != '1' && binary[i] != '.') {
            if ((int)binary[i] != 0) {
                status = false;
            }
            break;
        }
        
        if (binary[i] == '.') {
            positive = false;
            continue;
        }
        
        if (positive && pos_idx > 64) {
            status = false;
            error_no = 1;
            break;
        } else if (!positive && neg_idx > 52) {
            status = false;
            error_no = 2;
            break;
        }
        
        if (positive) {
            if (binary[i] == '1') {
                positive_arr[pos_idx] = 1;
            } else {
                positive_arr[pos_idx] = 0;
            }
            pos_idx++;
        } else {
            if (binary[i] == '1') {
                negative_arr[neg_idx] = 1;
            } else {
                negative_arr[neg_idx] = 0;
            }
            neg_idx++;
        }
    }
    
    if (status) {
        int binary_postive_number = 0;
        if (pos_idx > 0) {
            for (int i = 0; i < pos_idx; i++) {
                if (positive_arr[i] > 0) {
                    binary_postive_number += pow(2, pos_idx - (i + 1));
                }
            }
        }
                
        double binary_negative_number = 0;
        for (int i = 1; i <= neg_idx; i++) {
            if (negative_arr[i - 1] > 0) {
                binary_negative_number += pow(2, -i);
            }
        }

        double binary_result = 0.0;
        if (pos_idx == 0 && neg_idx == 0) {
            printf("Result: none/n");
        } else {
            binary_result = binary_postive_number + binary_negative_number;
            printf("Result: %.52lg\n", binary_result);
        }
    } else {
        result = 0;
        switch (error_no) {
            case 1:
                printf("Number of binary number exceed 20!!\n");
                break;
                
            case 2:
                printf("Number of binary points exceed 52!!\n");
                break;
                
            default:
                printf("You entered invalid binary!!\n");
        }
    }
    
    return result;
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
