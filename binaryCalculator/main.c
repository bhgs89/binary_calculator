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
                printf("Number of binary number exceed 64!!\n");
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

int runDecimalToBinary(void) {
    int result = 0;
    char decimal[42];
    bool status = true;
    int error_no = 0;
    
    printf("===============================\n");
    printf("***          No space allowed       ***\n");
    printf("*** Max number of decimal number: 20 ***\n");
    printf("*** Max number of decimal points: 20 ***\n");
    printf("Enter number: ");
    scanf("%s", decimal);
    
    bool positive = true;
    int pos_idx = 0;
    int neg_idx = 0;
    int positive_arr[20], negative_arr[20];
    int count_points = 0;
    
    for (int i = 0; i < 42; i++) {
        if (decimal[i] == '.') {
            count_points++;
        }
        
        if (count_points >= 2) {
            status = false;
            break;
        }
        
        if (((int)decimal[i] >= 48 && (int)decimal[i] <= 57) || (int)decimal[i] == 46 || (int)decimal[i] == 0) {
            if (decimal[i] == '.') {
                positive = false;
                continue;
            } else if ((int)decimal[i] == 0) {
                break;
            }
            
            if (positive && pos_idx > 20) {
                status = false;
                error_no = 1;
                break;
            } else if (!positive && neg_idx > 20) {
                status = false;
                error_no = 2;
                break;
            }
            
            if (positive) {
                switch ((int)decimal[i]) {
                    case 48:
                        positive_arr[pos_idx] = 0;
                        pos_idx++;
                        break;
                    case 49:
                        positive_arr[pos_idx] = 1;
                        pos_idx++;
                        break;
                    case 50:
                        positive_arr[pos_idx] = 2;
                        pos_idx++;
                        break;
                    case 51:
                        positive_arr[pos_idx] = 3;
                        pos_idx++;
                        break;
                    case 52:
                        positive_arr[pos_idx] = 4;
                        pos_idx++;
                        break;
                    case 53:
                        positive_arr[pos_idx] = 5;
                        pos_idx++;
                        break;
                    case 54:
                        positive_arr[pos_idx] = 6;
                        pos_idx++;
                        break;
                    case 55:
                        positive_arr[pos_idx] = 7;
                        pos_idx++;
                        break;
                    case 56:
                        positive_arr[pos_idx] = 8;
                        pos_idx++;
                        break;
                    case 57:
                        positive_arr[pos_idx] = 9;
                        pos_idx++;
                        break;
                }
            } else {
                switch ((int)decimal[i]) {
                    case 48:
                        negative_arr[neg_idx] = 0;
                        neg_idx++;
                        break;
                    case 49:
                        negative_arr[neg_idx] = 1;
                        neg_idx++;
                        break;
                    case 50:
                        negative_arr[neg_idx] = 2;
                        neg_idx++;
                        break;
                    case 51:
                        negative_arr[neg_idx] = 3;
                        neg_idx++;
                        break;
                    case 52:
                        negative_arr[neg_idx] = 4;
                        neg_idx++;
                        break;
                    case 53:
                        negative_arr[neg_idx] = 5;
                        neg_idx++;
                        break;
                    case 54:
                        negative_arr[neg_idx] = 6;
                        neg_idx++;
                        break;
                    case 55:
                        negative_arr[neg_idx] = 7;
                        neg_idx++;
                        break;
                    case 56:
                        negative_arr[neg_idx] = 8;
                        neg_idx++;
                        break;
                    case 57:
                        negative_arr[neg_idx] = 9;
                        neg_idx++;
                        break;
                }
            }
        } else {
            status = false;
            break;
        }
    }
    
    if (status) {
        int decimal_number = 0;
        if (pos_idx > 0) {
            for (int i = 0; i < pos_idx; i++) {
                decimal_number += positive_arr[i] * pow(10, pos_idx - (i + 1));
            }
        }
                
        int decimal_point = 0;
        for (int i = 0; i <= neg_idx; i++) {
            decimal_point += negative_arr[i] * pow(10, neg_idx - (i + 1));
        }
        
        char result_binary[200];
        char positive_binary[100];
        char negative_binary[100];
        int result_idx = 0;
        int pos_binary_idx = 0;
        int neg_binary_idx = 0;
        
        if (decimal_number > 0) {
            int binary_number;
            do {
                binary_number = decimal_number % 2;
                decimal_number = decimal_number / 2;
                if (binary_number == 0) {
                    positive_binary[pos_binary_idx++] = '0';
                } else if (binary_number == 1) {
                    positive_binary[pos_binary_idx++] = '1';
                }
            } while (decimal_number != 0);
            for (int i = 1; i <= pos_binary_idx; i++) {
                result_binary[i - 1] = positive_binary[pos_binary_idx - i];
            }
        } else {
            result_binary[0] = '0';
            result_binary[1] = '.';
            result_idx = 2;
        }
        
        if (decimal_point > 0) {
//            int binary_number;
//            do {
//                binary_number = (decimal_point * pow(10, -neg_idx)) * 2;
//                decimal_number = decimal_number / 2;
//                if (binary_number == 0) {
//                    positive_binary[pos_binary_idx++] = '0';
//                } else if (binary_number == 1) {
//                    positive_binary[pos_binary_idx++] = '1';
//                }
//            } while (decimal_number != 0);
//            for (int i = 1; i <= pos_binary_idx; i++) {
//                result_binary[i - 1] = positive_binary[pos_binary_idx - i];
//            }
        }
        
        if (pos_idx == 0 && neg_idx == 0) {
            printf("Result: none\n");
        } else {
            printf("Result: %s\n", result_binary);
        }
    } else {
        result = 0;
        switch (error_no) {
            case 1:
                printf("Number of decimal number exceed 20!!\n");
                break;
                
            case 2:
                printf("Number of decimal points exceed 20!!\n");
                break;
                
            default:
                printf("You entered invalid number!!\n");
        }
    }
    
    return result;
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
            num = runDecimalToBinary();
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
