#include <iostream>
#include <cmath>
#define max 1000

long double power(long double bnum, char input[],short *n);
long double extension(char bopt, long double bnum, char input[],short *n);
long double cal(char input[],short *n);
long double cal(char input[]);

int main(){
    printf("=== Calculator Version 1.0 ===\n");
    while(1){
        printf("Enter Equation: ");
        char input[max] = {};
        for(short n = 0;input[n] != '=';)n += (((input[n] = getchar()) < 58 || input[n] == 'e' || input[n] == 'E' || input[n] == '^')&& input[n] != 44 && input[n] > 39);
        printf("Result: %Lf\n",cal(input));
        std::cout << "      : " << cal(input) << "\n\n";
    }
}

long double power(long double bnum, char input[],short *n){
	long double num[3] = {0,bnum,0};
	char opt[1] = {'^'};
	do{
		num[0] = num[1];

        if(sscanf(&input[*n],"%Lf",&num[1])==0){
            if(input[*n] == '('){
            	(*n)++;
            	num[1] = cal(&input[0], n);
            	if(input[*n] > ('0'-1) && input[*n] < ('9'+1) ){
            		sscanf(&input[*n],"%Lf",&num[2]);
            		num[1] *= num[2];
            		while((input[++(*n)] > ('0'-1) || input[*n] == '.') && (input[*n] < ('9'+1) || input[*n] == 'e' || input[*n] == 'E'));
            		opt[1] = input[(*n)++];
            	}
            	else{
                    (*n)--;
            		while((input[++(*n)] > ('0'-1) || input[*n] == '.') && (input[*n] < ('9'+1) || input[*n] == 'e' || input[*n] == 'E'));
            		opt[1] = input[(*n)++];
            	}
            }
            else{
            	printf("Error\n");
            	return 0;
            }
        }
        else{
        	while((input[++(*n)] > ('0'-1) || input[*n] == '.') && (input[*n] < ('9'+1) || input[*n] == 'e' || input[*n] == 'E'));
        	opt[1] = input[(*n)++];
        }
        
        c:
        if(opt[1] == '('){
        	num[1] *= cal(&input[0], n);
        	if(input[*n] > ('0'-1) && input[*n] < ('9'+1) ){
            		sscanf(&input[*n],"%Lf",&num[2]);
            		num[1] *= num[2];
            		while((input[++(*n)] > ('0'-1) || input[*n] == '.') && (input[*n] < ('9'+1) || input[*n] == 'e' || input[*n] == 'E'));
            		opt[1] = input[(*n)++];
            		goto c;
            	}
        	else{
        		opt[1] = input[(*n)++];
        	}
        }
        
        num[1] = pow(num[0],num[1]);
        
	}while(opt[1] == '^');
	return num[1];
}
long double extension(char bopt, long double bnum, char input[],short *n){
	long double num[3] = {0,bnum,0};
	char opt[2] = {0,bopt};
	do{
        num[0] = num[1];
        opt[0] = opt[1];

        if(sscanf(&input[*n],"%Lf",&num[1])==0){
            if(input[*n] == '('){
            	(*n)++;
            	num[1] = cal(&input[0], n);
            	if(input[*n] > ('0'-1) && input[*n] < ('9'+1) ){
            		sscanf(&input[*n],"%Lf",&num[2]);
            		num[1] *= num[2];
            		while((input[++(*n)] > ('0'-1) || input[*n] == '.') && (input[*n] < ('9'+1) || input[*n] == 'e' || input[*n] == 'E'));
            		opt[1] = input[(*n)++];
            	}
            	else{
                    (*n)--;
            		while((input[++(*n)] > ('0'-1) || input[*n] == '.') && (input[*n] < ('9'+1) || input[*n] == 'e' || input[*n] == 'E'));
            		opt[1] = input[(*n)++];
            	}
            }
            else{
            	printf("Error\n");
            	return 0;
            }
        }
        else{
        	while((input[++(*n)] > ('0'-1) || input[*n] == '.') && (input[*n] < ('9'+1) || input[*n] == 'e' || input[*n] == 'E'));
        	opt[1] = input[(*n)++];
        }
        
        b:
        if(opt[1] == '('){
        	num[1] *= cal(&input[0], n);
        	if(input[*n] > ('0'-1) && input[*n] < ('9'+1) ){
            		sscanf(&input[*n],"%Lf",&num[2]);
            		num[1] *= num[2];
            		while((input[++(*n)] > ('0'-1) || input[*n] == '.') && (input[*n] < ('9'+1) || input[*n] == 'e' || input[*n] == 'E'));
            		opt[1] = input[(*n)++];
            		goto b;
            	}
        	else{
        		opt[1] = input[(*n)++];
        	}
        }
        if(opt[1] == '^'){num[1] = power(num[1], &input[0], n); opt[1] = input[(*n)-1];}
        
        if(opt[0] == '*')num[1] = num[0] * num[1];
        else if(opt[0] == '/')num[1] = num[0] / num[1];
        
	}while(opt[1] == '*' || opt[1] == '/');
	return num[1];
}

long double cal(char input[],short *n){
    long double num[3] = {};
    long double opt[2] = {};

    do{
        num[0] = num[1];
        opt[0] = opt[1];

        if(sscanf(&input[*n],"%Lf",&num[1])==0){
            if(input[*n] == '('){
            	(*n)++;
            	num[1] = cal(&input[0], n);
            	if(input[*n] > ('0'-1) && input[*n] < ('9'+1) ){
            		sscanf(&input[*n],"%Lf",&num[2]);
            		num[1] *= num[2];
            		while((input[++(*n)] > ('0'-1) || input[*n] == '.') && (input[*n] < ('9'+1) || input[*n] == 'e' || input[*n] == 'E'));
            		opt[1] = input[(*n)++];
            	}
            	else{
                    (*n)--;
            		while((input[++(*n)] > ('0'-1) || input[*n] == '.') && (input[*n] < ('9'+1) || input[*n] == 'e' || input[*n] == 'E'));
            		opt[1] = input[(*n)++];
            	}
            }
            else{
            	printf("Error\n");
            	return 0;
            }
        }
        else{
        	while((input[++(*n)] > ('0'-1) || input[*n] == '.') && (input[*n] < ('9'+1) || input[*n] == 'e' || input[*n] == 'E'));
        	opt[1] = input[(*n)++];
        }
        
        a:
        if(opt[1] == '('){
        	num[1] *= cal(&input[0], n);
        	if(input[*n] > ('0'-1) && input[*n] < ('9'+1) ){
            		sscanf(&input[*n],"%Lf",&num[2]);
            		num[1] *= num[2];
            		while((input[++(*n)] > ('0'-1) || input[*n] == '.') && (input[*n] < ('9'+1) || input[*n] == 'e' || input[*n] == 'E'));
            		opt[1] = input[(*n)++];
            		goto a;
            	}
        	else{
        		opt[1] = input[(*n)++];
        	}
        }
        if(opt[1] == '^'){num[1] = power(num[1], &input[0], n); opt[1] = input[(*n)-1];}
        if(opt[1] == '*' || opt[1] == '/'){num[1] = extension(opt[1], num[1], &input[0], n); opt[1] = input[(*n)-1];}

        if(opt[0] == '+')num[1] = num[0] + num[1];
        else if(opt[0] == '-')num[1] = num[0] - num[1];

    }while(opt[1] != '=' && opt[1] != ')');
    return num[1];
}
long double cal(char input[]){
    short n = 0;
    return cal(&input[0],&n);

}