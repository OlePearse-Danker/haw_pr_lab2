


#include <stdio.h>
#include <stdlib.h>

// Funktionsdeklarationen
int is_even(int input);
int is_prime(int input);


short get_short(char text[], short MIN, short MAX);
void print_prime_factors(int user_input);

int main ()
{   
    system("clear");
    unsigned int user_input;

    user_input = get_short("Enter a number between 0 and 1000", 0, 1000);

    // checking if the number is even or odd
    if (is_even(user_input))
    {
        printf("Entered number is even\n");  
    }
    else
    {
        printf("Entered number is odd\n");  
    }

    // checking if the number is prime or not
    if (is_prime(user_input))
    {
        printf("Entered number is a prime\n");  
    }
    else
    {
        printf("Entered number is not a prime\n");  
    } 
    

    // print all prime factors up until user input

    printf("-------------------------------\n");
    printf("All primes until user input\n");
    printf("-------------------------------\n");
    for (int i = 0; i < user_input; i++)
    {
        if (is_prime(i))
        {
            printf("%d is a prime\n", i);
        }
        
    }

    // printing prime_factors
    print_prime_factors(user_input);
    

    return 0;
}

// Function Definitions
int is_even(int input)
{
    return ((input % 2) == 0);
}


int is_prime(int input)
{
    if (input == 1)
    {
        return 0;
    }

    if (input == 2)
    {
        return 1;
    }

    // if the number has a factor, it is not a prime
    for (int i = 2; i < input; i++)
    {
        if (input % 2 == 0)
        {
            return 0;
        }
        
    }

    return 1;
    
}


short get_short(char text[], short MIN, short MAX)
{
    //declare working variables 
    short value;
    int finished = 0; //0 f�r FALSE
    char ch;
    int retVal;

    do
    {
        printf("%s: ", text); //Abk�rzung "s" f�r "string" / Zeichenkette

        ch = '\0'; // \0 wird als ein Buchstabe gewertet; O ist nicht die Zahl 0 sondern ein "Null Character"; Null Character hat in der Ascii Tabelle auch den Wert 0

        retVal = scanf("%hd%c", &value, &ch); // -> "hd" steht f�r short -> Adresse ist "Value"; scanf gibt auch einen Wert zur�ck, diesen speichern wir in retVal 

        // check for valid user input
        if (retVal != 2) printf("Das war keine korrekte Zahl!\n");
        else if (ch != '\n') printf("Unerwartete Zeichen hinter der Zahl!\n");
        else if (value < MIN) printf("Zahl ist zu klein (MIN: %hd)\n", MIN);
        else if (value > MAX) printf("Zahl ist zu gro%c (MAX: %hd)\n", 225, MAX);
        else finished = 1; // falls die Variable tats�chlich 2 ist; und der character ein newline, ist alles richtig und die loop wird beendet

        //Variable finished wird auf 1 gesetzt -> weil 1 f�r TRUE

        //clear input stream buffer
        while (ch != '\n') scanf("%c", &ch); //Variation mit scanf von getchar

    } while (!finished); //repeat if not finished 

    //return user input
    return value; //wer auch immer die Funktion get_short aufruft bekomm "value" zur�ck
}

void print_prime_factors(int user_input)
{

    printf("-------------------------------\n");
    printf("Computing primefactors\n");
    printf("-------------------------------\n");

    int f = 2;

    do
    {
        if ((user_input % f) == 0)
        {
            user_input /= f;
            printf("%d\n", f );
        }
        else
        {
            do
            {
                f++;
            } while (!is_prime(f));
            
        }
        
        
    } while (user_input > 1);
    
}
