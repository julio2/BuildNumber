/* A C++ program to implement itoa() */
// Source: https://www.geeksforgeeks.org/implement-itoa/

void reverse(char str[], int length);


char* itoaj(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;

    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverse(str, i);

    return str;
}




/* A utility function to reverse a string  */
void reverse(char str[], int length)
{
    int start = 0;
    char aux;
    int end = length -1;
    while (start < end)
    {
        aux= *(str+start);
        *(str+start)= *(str+end);
        *(str+end) = aux;
        start++;
        end--;
    }

}
