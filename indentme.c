#include <stdio.h>

int main()
{
    int ch, whsp = 0, stline = 1, blocks = 0, i;
    int hash = 0;          //The hashtah variable
    int apo = 0, apoz = 0; //Quote's variable's : apo is use for double quotes and apoz for single quotes
    int slash = 0, s2 = 0; //Slash (\) variable's :  slash is used for a single slash (\) and s2 is used for double slash (\\)
    int par = 0;           //par is the variable used for parenthesis

    while ((ch = getchar()) != EOF)
    {

        if (ch == '#' || hash == 1) //Checking if the currect character is a #
        {
            hash = 1; //if it is the hash counter turns to 1 which means that we're in a hashtag
            if (ch == '\n')
            {
                stline = 1;
                hash = 0;
                putchar(ch);
                continue;
            }
            putchar(ch);
            continue;
        }

        if (ch == '(' && (apo == 0 && apoz == 0)) //Checking if the currect character is a (
        {
            par++; //counting the parenthesis
        }
        if (ch == ')' && (apo == 0 && apoz == 0)) //Checking if the currect character is a )
        {
            par--; //Removing -1 from the counter beacause the parenthesis ended the parenthesis
        }
        if (ch == '\\') //checking if the current character is a slash
        {
            if (ch == '\\' && slash == 1) //Checking if the character is a double slash (\\)
            {
                putchar(ch);
                s2 == 1; //Turning s2(slash 2) from 0 to 1 to state that a double slash (\\) exists
                slash = 0;
                continue;
            }
            slash = 1;
        }

        if (ch == ' ' || ch == '\t' || ch == '\n') //Checking if the current character is  whitespace newline or /t
        {
            if (apo == 0 && apoz == 0) //Checking if the current character inside single or double quotes
            {
                whsp = 1;
                continue;
            }
        }

        if (ch == '}' && (apo == 0 && apoz == 0)) //Checking if the current character inside single or double quotes  and if the character is }
        {
            blocks--;
        }

        if (stline == 1 && hash != 1) //checking if the current character is in a hashtag
        {

            for (i = 0; i < blocks; i++)
            {

                putchar('\t');
            }
        }

        if (ch == '\"' || ch == '\'') //Checking if the charcter is a sigle or double quote
        {

            if (ch == '\"' && apoz != 1) // checking if the character is a double quote providing that a it's not in a single quote
            {
                if (slash == 0 && apo == 1) //   Checking if a slash (\) does not exist providing that we're still inside the double quotes
                {

                    apo = 0;
                    putchar(ch);
                    continue;
                }
                if (slash == 0 && apo != 1) //If the character is a double quote and we're not in a slash (\) or a sigle quote  i state that the character is a double quote by turning the variable apo from 0 to 1
                {

                    apo = 1;
                }
            }

            if (ch == '\'' && apo != 1) //checking if the character is a single quote providing that a it's not in a double quote
            {

                if (slash == 0 && apoz == 1) //Checking if a slash (\) does not exist providing that we're still inside the single quote
                {

                    putchar(ch);
                    apoz = 0;
                    continue;
                }
                if (slash == 0 && apoz != 1) //If the character is a single quote and we're not in a slash (\) or a double quote,  i state that the character is a double quote by turning the variable apoz from 0 to 1
                {
                    apoz = 1;
                }
            }
        }

        if (ch != '\\') //If the character is anything other than (/)
        {
            slash = 0;
            s2 = 0;
        }
        if (ch == ';' || ch == '{' || ch == '}')
        {
            if (ch == '{' && (apo == 0 && apoz == 0) && hash == 0) //Checking if the character is ( { ) providing that we're not in single or double quote or a hashtag
            {
                if (ch == '{' && stline == 0)
                {
                    putchar(' ');
                }

                blocks++;
            }

            if (apo == 0 && apoz == 0 && par == 0) //If we're not in single or double quote or a parenthesis
            {

                putchar(ch);
                putchar('\n');
                whsp = 0;
                stline = 1;
                continue;
            }
        }

        if (whsp == 1 && stline == 0)
        {

            putchar(' ');
        }
        whsp = 0;
        stline = 0;
        putchar(ch);
    }
}
