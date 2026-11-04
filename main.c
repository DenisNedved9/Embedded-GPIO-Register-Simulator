#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bit_position = 0;
char input[50] = "";

int set_pin_high(int pin)
{

    printf("What bit do you want to put on? (from 1 to 8)\n");
    scanf("%d", &bit_position); // načte 1 až 8
    bit_position--;

    unsigned int mask = 1 << bit_position;
    // udělá osmibitovou masku s '1' na té pozici co zadáme vůči které následně porovnáváme

    pin = pin | mask; // najde bit který je na stejném místě jako maska

    printf("__________________________\n\n");

    return pin;
}

int set_pin_low(int pin)
{

    printf("What bit do you want to put off? (from 1 to 8)\n");
    scanf(" %d", &bit_position);
    bit_position--;

    unsigned int mask = 1 << bit_position;

    pin = pin & ~(mask);

    printf("__________________________\n\n");

    return pin;
}

int toggle_pin(int pin)
{
    printf("What bit do you want to switch? (from 1 to 8)\n");
    scanf(" %d", &bit_position);
    bit_position--;

    unsigned int mask = 1 << bit_position;

    pin ^= mask;

    printf("__________________________\n\n");

    return pin;
}

int check_pin(int pin)
{
    printf("What bit do you want to check? (from 1 to 8)\n");
    scanf(" %d", &bit_position);
    bit_position--;

    printf("%s\n", (pin & (1 << bit_position)) ? "This pin is on!" : "This pin is off!");

    printf("__________________________\n\n");

    return pin;
}
void print_binary(unsigned int reg)
{
    printf("Pins state (8..1): ");
    for (int i = 7; i >= 0; i--) // jde od 7 dolů
    {
        printf("%d", (reg >> i) & 1); // posune a porovná, v kazdém loopu to printne buď 1 nebo 0.
    }
    printf(" (Decimal: %d)\n", reg);
}

int main()
{
    unsigned int port_register = 0;

    while (1)
    {

        printf("Value of the pins: %d\n", port_register);

        printf("What action do you want to perform!\n'pinon' - turn the pin on\n'pinlow' - set pin off\n'tgpin' - toggle the pin to the opposite value\n'ispin' - check if the pin is on\n'bin' - shows you the pins\n'end' - ends the program\n>> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // odendá s konce řádku to že jde na další řádek

        if (strcmp(input, "end") == 0)
        {
            break;
        }

        if (strcmp(input, "pinon") == 0)
        {
            port_register = set_pin_high(port_register);
        }
        else if (strcmp(input, "pinlow") == 0)
        {
            port_register = set_pin_low(port_register);
        }
        else if (strcmp(input, "tgpin") == 0)
        {
            port_register = toggle_pin(port_register);
        }
        else if (strcmp(input, "ispin") == 0)
        {
            check_pin(port_register);
        }
        else if (strcmp(input, "bin") == 0)
        {
            print_binary(port_register);
            continue;
        }
        scanf("%*c");
    }
    printf("Program ended!");

    return 0;
}