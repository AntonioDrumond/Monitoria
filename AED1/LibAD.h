#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const   char STR_EMPTY [] =  "" ;

/**
 * @brief Method for testing code
*/
void flag()
{
    printf("\nFLAG\n");
    getchar();
}

/**
 * @brief Prints in the terminal a line made of "=" characters
 * @param length The length of the line
 */
void EQUALINE(int length) 
{
    for (int i = 0; i < length; i++) 
    {
        printf("=");
    }
    printf("\n");
}

/**
 * @brief Prints a header menu in the terminal
 * @param a first bit of text to be print, usually personal info
 * @param b second bit of text to be print, usually the author's name
 * @return int - Whether the function suceeded in it's task
 */
int Header(const char* a, const char* b) 
{
    int comprimentoTotal = strlen(a) + strlen(b) + 3;
    printf("Info: 999999 Name: YOUR_NAME_HERE\n\n");
    EQUALINE(comprimentoTotal);
    printf("%s - %s\n", a, b);
    EQUALINE(comprimentoTotal);
    printf("\n");
    return EXIT_SUCCESS;
}

/**
 * @brief Function that allocates space for a string
 * @param size amount of characters
 * @return char* - reserved space, if exists, NULL if it doesn't
 */
char* allocChar (int size)
{
    return ( (char*) malloc(abs(size) * sizeof(char)) );
}

/**
 * @brief Function that allocates space for integer numbers
 * @param size amount of numbers
 * @return char* - reserved space, if exists, NULL if it doesn't
 */
int* allocInt (int size)
{
    return ( (int*) malloc(abs(size) * sizeof(int)) );
}

/**
    @brief Function that converts an integer number to a sequence of characters
    @param x integer value
    @return sequence with the result
 */
char* intToString (int x)
{
    char* buffer = allocChar(64+1);
    sprintf(buffer, "%d", x);
    return buffer;
}

/**
    @brief Function that converts a real number to a sequence of characters
    @param x real value
    @return sequence with the result
 */
char* doubleToString (double x)
{
    char* buffer = allocChar(64+1);
    sprintf(buffer, "%lf", x);
    return buffer;
}

/**
 * @brief returns a random positive number between a and b. If put on a loop, 
 * is recommended to multiply the third parameter for each iteration
 * @param a is the lower limit
 * @param b is the higher limit
 * @param seed is the seed of the random generation. Preferably use time(NULL)
 * @return the random numer, or -1 if the parameters are invalid
 */
int randInt(int a, int b, int seed)
{
    if(0<a && a<b)
    {
        srand(seed);
        int x = rand()%(b-a+1)+a;
        return x;
    }
    else return -1;
}

/**
 * @brief Better alternative to getchar();
 */
void clear()
{
    int  x = 0;
    do { x = getchar( ); } while ( x != EOF && x != '\n' );
    clearerr ( stdin ); 
}

/**
    @brief Function that concatenates two sequences of characters
    @param text1 First sequence
    @param text2 Second sequence
    @return char* - the combination of the two sequences
 */
char* concat (const char * const text1, const char * const text2)
{
    char* buffer = allocChar(strlen(text1)+strlen(text2)+1);
    strcpy(buffer, text1);
    strcat(buffer, text2);
    return buffer;
}

/**
 * @brief Function that returns the inverse of a number in the form of a string
 * 
 * @param x The number in question
 * @return char* - 1/x
 */
char* inverseInt (int x)
{
    char* var = (char*) malloc(10 * sizeof(char));
    if(x==1){snprintf(var, 10, "1");}
    else {snprintf(var, 10, "1/%d", x);}
    return var;
}

/**
 * @brief Function that reads a sequence of characters and stores it in a variable
 * @param par the variable in question
 * @return char* - the sequence of characters read
 */
char *readString(char *par)
{
    printf("Digite uma palavra: ");
    fgets ( par, 100-1, stdin);
    par[strlen(par)-1]='\0';
    return par;
}

/**
 * @brief Function that prints text to the termial, thenreads a sequence of characters and stores it in a variable
 * @param par the variable in question
 * @param text the text that is going to be printed in the terminal
 * @return char* - the sequence of characters read
 */
char *readStringT(char *var, char *text)
{
    printf("%s", text);
    fgets ( var, 100-1, stdin);
    var[strlen(var)-1]='\0';
    return var;
}

/**
 * @brief prints text to the terminal, reads an integer value and stores in a variable. 
 * 
 * @param var is the target variable
 * @param text is the text to be print
 * @return int
 */
int readIntT(int *var, char* text)
{
    int resultado;
    printf("%s", text);
    resultado = scanf(" %d", var); getchar();
    while (resultado != 1)
    {
        getchar();
        printf("%s", "Entrada invalida, por favor digite um numero inteiro: ");
        resultado = scanf("%d", var); getchar();
    }
    return *var;
}

/**
 * @brief prints text to the terminal, reads a real value and stores in a variable. 
 * 
 * @param var is the target variable
 * @param text is the text to be print
 * @return double - The value read
 */
double readDoubleT(double *var, char *text)
{
    double resultado;
    printf("%s", text);
    resultado = scanf("%lf", var); getchar();
    while (resultado != 1)
    {
        getchar();
        printf("%s", "Entrada invalida, por favor digite um numero real: ");
        resultado = scanf("%lf", var); getchar();
    }
    return *var;
}

/**
 * @brief Prints out the first n elements in an array
 * @param arr The array to be printed
 * @param n The amount of elements to be printed
 */
void printfArrInt (int arr[], int n)
{
    int i = 0;
    for(i=0; i<n; i++) printf("%d\n", arr[i]);
}

/**
 * @brief Prints out the first n elements in an array in a file
 * @param fil The file where the numbers will be print
 * @param arr The array to be printed
 * @param n The amount of elements to be printed
 */
void fprintArrInt (FILE* fil, int arr[], int n)
{
    int i = 0;
    for(i=0; i<n; i++) fprintf(fil, "%d\n", arr[i]);
}

/**
 * @brief Prints the contents of a matrix with integer values
 * @param i the amount of rows in the matrix
 * @param j the amount of columns in the matrix
 * @param mat the matrix itself
 */
void printMatInt (int i, int j, int mat[][j])
{
    int i1 = 0, j1 = 0;
    for (i1=0; i1<i; i1++)
    {
        for (j1=0; j1<j; j1++)
        {
            printf("%d ", mat[i1][j1]);
        }
        printf("\n");
    }
}

/**
 * @brief Prints the contents of a matrix with integer values
 * @param i the amount of rows in the matrix
 * @param j the amount of columns in the matrix
 * @param mat the matrix itself
 */
void printMatIntPtr (int i, int j, int** mat)
{
    int i1 = 0, j1 = 0;
    for (i1=0; i1<i; i1++)
    {
        for (j1=0; j1<j; j1++)
        {
            printf("%d ", *(*(mat+i1)+j1));
        }
        printf("\n");
    }
}

/**
 * @brief Prints the contents of a matrix with real values
 * @param i the amount of rows in the matrix
 * @param j the amount of columns in the matrix
 * @param mat the matrix itself
 */
void printMatDouble (int i, int j, double mat[][j])
{
    int i1 = 0, j1 = 0;
    for (i1=0; i1<i; i1++)
    {
        for (j1=0; j1<j; j1++)
        {
            printf("%0.3lf ", mat[i1][j1]);
        }
        printf("\n");
    }
}

/**
 * @brief Prints the contents of the main diagonal of a matrix with real values
 * @param i the amount of rows in the matrix
 * @param j the amount of columns in the matrix
 * @param mat the matrix itself
 */
void printMatDiagDouble (int i, int j, double mat[][j])
{
    int i1 = 0, j1 = 0;
    if(i==j)
    {
        for (i1=0; i1<i; i1++)
        {
            for (j1=0; j1<j; j1++)
            {
                if(i1!=j1) printf("------ ");
                else printf("%0.3lf ", mat[i1][j1]);
            }
            printf("\n");
        }
    }
    else printf("ERRO: Matriz com dimensoes invalidas.");
}

/**
 * @brief Prints the contents of the secondary diagonal of a matrix with real values
 * @param i the amount of rows in the matrix
 * @param j the amount of columns in the matrix
 * @param mat the matrix itself
 */
void printMatDiagSDouble (int i, int j, double mat[][j])
{
    int i1 = 0, j1 = 0;
    int x = 0, y = j-1;
    if(i==j)
    {
        for (i1=0; i1<i; i1++)
        {
            for (j1=0; j1<j; j1++)
            {
                if(i1==x && j1==y) printf("%0.3lf ", mat[i1][j1]);
                else printf("------ ");
            }
            printf("\n");
            x++; y--;
        }
    }
    else printf("ERRO: Matriz com dimensoes invalidas.");
}

/**
 * @brief Prints the contents of the main diagonal and over it of a matrix with real values
 * @param i the amount of rows in the matrix
 * @param j the amount of columns in the matrix
 * @param mat the matrix itself
 */
void printMatDiagUnDouble (int i, int j, double mat[][j])
{
    int i1 = 0, j1 = 0;
    if(i==j)
    {
        for (i1=0; i1<i; i1++)
        {
            for (j1=0; j1<j; j1++)
            {
                if(i1==j1 || i1>j1) printf("%0.3lf ", mat[i1][j1]);
                else printf("------ ");
            }
            printf("\n");
        }
    }
    else printf("ERRO: Matriz com dimensoes invalidas.");
}

/**
 * @brief Prints the contents of the main diagonal and under it of a matrix with real values
 * @param i the amount of rows in the matrix
 * @param j the amount of columns in the matrix
 * @param mat the matrix itself
 */
void printMatDiagOvDouble (int i, int j, double mat[][j])
{
    int i1 = 0, j1 = 0;
    if(i==j)
    {
        for (i1=0; i1<i; i1++)
        {
            for (j1=0; j1<j; j1++)
            {
                if(i1==j1 || i1<j1) printf("%0.3lf ", mat[i1][j1]);
                else printf("------ ");
            }
            printf("\n");
        }
    }
    else printf("ERRO: Matriz com dimensoes invalidas.");
}

/**
 * @brief Prints the contents of the secondary diagonal and under it of a matrix with real values
 * @param i the amount of rows in the matrix
 * @param j the amount of columns in the matrix
 * @param mat the matrix itself
 */
void printMatDiagSUnDouble (int i, int j, double mat[][j])
{
    int i1 = 0, j1 = 0;
    int x = 0, y = j-1;
    if(i==j)
    {
        for (i1=0; i1<i; i1++)
        {
            for (j1=0; j1<j; j1++)
            {
                if(i1<=x && j1>=y) printf("%0.3lf ", mat[i1][j1]);
                else printf("------ ");
            }
            printf("\n");
            x++; y--;
        }
    }
    else printf("ERRO: Matriz com dimensoes invalidas.");
}

/**
 * @brief Prints the contents of the secondary diagonal and under it of a matrix with real values
 * @param i the amount of rows in the matrix
 * @param j the amount of columns in the matrix
 * @param mat the matrix itself
 */
void printMatDiagSOvDouble (int i, int j, double mat[][j])
{
    int i1 = 0, j1 = 0;
    int x = 0, y = j-1;
    if(i==j)
    {
        for (i1=0; i1<i; i1++)
        {
            for (j1=0; j1<j; j1++)
            {
                if(i1>=x && j1<=y) printf("%0.3lf ", mat[i1][j1]);
                else printf("------ ");
            }
            printf("\n");
            x++; y--;
        }
    }
    else printf("ERRO: Matriz com dimensoes invalidas.");
}

/**
 * @brief Prints the contents of a matrix with real values into a file
 * @param fil the file where the values should be print
 * @param i the amount of rows in the matrix
 * @param j the amount of columns in the matrix
 * @param mat the matrix itself
 */
void fprintMatDouble (FILE* fil, int i, int j, double mat[][j])
{
    int i1 = 0, j1 = 0;
    for (i1=0; i1<i; i1++)
    {
        for (j1=0; j1<j; j1++)
        {
            fprintf(fil, "%0.3lf ", mat[i1][j1]);
        }
        fprintf(fil, "\n");
    }
}

/**
 * @brief Prints the contents of a matrix with integer values into a file
 * @param fil the file where the values should be print
 * @param i the amount of rows in the matrix
 * @param j the amount of columns in the matrix
 * @param mat the matrix itself
 */
void fprintMatInt (FILE* fil, int i, int j, int mat[][j])
{
    int i1 = 0, j1 = 0;
    for (i1=0; i1<i; i1++)
    {
        for (j1=0; j1<j; j1++)
        {
            fprintf(fil, "%d ", mat[i1][j1]);
        }
        fprintf(fil, "\n");
    }
}

/**
 * @brief Reads integer values and stores them in a matrix
 * @param i the amount of rows in the matrix
 * @param j the amount of columns in the matrix
 * @param mat the matrix itself
 */
void readMatInt (int i, int j, int mat[][j])
{
    int i1 = 0, j1 = 0;
    int buffer = 0;
    char* text = allocChar(80);
    for (i1=0; i1<i; i1++)
    {
        for (j1=0; j1<j; j1++)
        {
            strcpy(text, "");
            readIntT(&buffer, concat(
                                    concat ( concat(text, intToString(i1)), "," ),
                                    concat ( concat(text, intToString(j1)), ":")));
            mat[i1][j1] = buffer;
        }
    }
}

/**
 * @brief Reads real values from a file and saves them into a matrix
 * 
 * @param fil the file to be read
 * @param i the number of lines in the matrix
 * @param j the number of columns in the matrix
 * @param mat the matrix where the values will be saved
 */
void freadMatInt (FILE* fil, int i, int j, int mat[][j])
{
   int i1 = 0, j1 = 0;
    int buffer = 0;
    for (i1=0; (i1<i && !feof(fil)); i1++)
    {
        for (j1=0; (j1<j && !feof(fil)); j1++)
        {
            fscanf(fil, " %d", &buffer);
            mat[i1][j1] = buffer;
        }
    }
}

/**
 * @brief Reads real values and stores them in a matrix
 * 
 * @param i the amount of rows in the matrix
 * @param j the amount of columns in the matrix
 * @param mat the matrix itself
 */
void readMatDouble (int i, int j, double mat[][j])
{
    int i1 = 0, j1 = 0;
    double buffer = 0.0;
    char* text = allocChar(80);
    for (i1=0; i1<i; i1++)
    {
        for (j1=0; j1<j; j1++)
        {
            strcpy(text, "");
            readDoubleT(&buffer, concat(
                                    concat ( concat(text, intToString(i1)), "," ),
                                    concat ( concat(text, intToString(j1)), ":")));
            mat[i1][j1] = buffer;
        }
    }
}

/**
 * @brief Reads real values from a file and saves them into a matrix
 * 
 * @param fil the file to be read
 * @param i the number of lines in the matrix
 * @param j the number of columns in the matrix
 * @param mat the matrix where the values will be saved
 */
void freadMatDouble (FILE* fil, int i, int j, double mat[][j])
{
   int i1 = 0, j1 = 0;
    double buffer = 0.0;
    for (i1=0; (i1<i && !feof(fil)); i1++)
    {
        for (j1=0; (j1<j && !feof(fil)); j1++)
        {
            fscanf(fil, " %lf", &buffer);
            mat[i1][j1] = buffer;
        }
    }
}

/**
 * @brief Transposes a matrix and saves the result in another matrix
 * @param i The amount of lines in the original matrix
 * @param j The amount of columns in the original matrix
 * @param mat The original matrix
 * @param trans The matrix where the transposed result should be saved
 */
void transposeMatrixInt(int i, int j, int mat[][j], int trans[][i])
{
    int i1 = 0, j1 = 0;
    for (i1=0; i1<i; i1++)
    {
        for (j1=0; j1<j; j1++)
        {
            trans[j1][i1] = mat[i1][j1];
        }
    }
}

/**
 * @brief Adds two matrixes, saving the result in the first one
 * @warning Make sure that the matrixes have the same size
 * @param i The amount of lines in the matrixes
 * @param j The amount of columns in the matrixes
 * @param mat1 The first matrix
 * @param mat2 The second matrix
 */
void addMatrixInt(int i, int j, int mat1[][j], int mat2[][j])
{
    int i1 = 0, j1 = 0;
    for (i1=0; i1<i; i1++)
    {
        for (j1=0; j1<j; j1++)
        {
            mat1[i1][j1] += mat2[i1][j1];
        }
    }
}

/**
 * @brief Adds two matrixes after multiplying the second one by a constant, saving the result in the first one
 * @warning Make sure that the matrixes have the same size
 * @param i The amount of lines in the matrixes
 * @param j The amount of columns in the matrixes
 * @param mat1 The first matrix
 * @param c The constant the second matrix should be multiplied by
 * @param mat2 The second matrix
 */
void addMatrixConstInt(int i, int j, int mat1[][j], int c, int mat2[][j])
{
    int i1 = 0, j1 = 0;
    for (i1=0; i1<i; i1++)
    {
        for (j1=0; j1<j; j1++)
        {
            mat1[i1][j1] += c * mat2[i1][j1];
        }
    }
}

int** multiplyMatrixInt(int im1, int jm1, int mat1[][jm1], int im2, int jm2, int mat2[][jm2])
{
    int** result = NULL; 
    if(jm1==im2)
    {
        result = (int**) malloc(im1*sizeof(int*));
        for(int i=0; i<im1; i++)
        {
            *(result+i) = (int*) calloc(jm2, sizeof(int));
        }
        for(int lin1=0; lin1<im1; lin1++)
        {
            for(int col2=0; col2<jm2; col2++)
            {
                for(int lin2=0; lin2<im2; lin2++)
                {
                    *(*(result+lin1)+col2) += (mat1[lin1][lin2] * mat2[lin2][col2]);  
                }
            }
        }
        int resDims = im1*jm2;
        int* data = (int*)malloc(1*resDims);
    }
    else printf("Tamanhos incompativeis");
    return result;
}

/**
 * @brief Returns if two matrixes with the same dimentions have the same elements
 * @param i The amount of lines in the matrixes
 * @param j The amount of columns in the matrixes
 * @param mat1 The first matrix
 * @param mat2 The second matrix
 * @return bool - whether the inserted matrixes are equal
 */
bool equalMatInt(int i, int j, int mat1[][j], int mat2[][j])
{
    int i1 = 0, j1 = 0, count = 0;
    for (i1=0; i1<i; i1++)
    {
        for (j1=0; j1<j; j1++)
        {
            if(mat1[i1][j1]!=mat2[i1][j1]) count++;
        }
    }
    return (count==0);
}

bool isUpperr(char x)
{return((x>='A')&&(x<='Z'));}

bool isLowerr(char x)
{return((x>='a')&&(x<='z'));}

bool isLetterr(char x)
{return(((x>='a')&&(x<='z'))||((x>='A')&&(x<='Z')));}

bool isNumberr(char x)
{return((x>='0')&&(x<='9'));}

/**
 * @brief Checks if an array's elements are ordered progressively.
 * 
 * @param arr the array to be checked
 * @param arrSize the size of the array
 * @return true if sorted
 * @return false if not sorted
 */
bool isArrIntSorted (int arr[], int arrSize)
{
    int count = 0;
    for (int i=0; i<arrSize-1; i++)
    {
        if(arr[i]>arr[i+1]) count++;
    };
    return count<1;
}

/**
 * @brief Checks if an array's elements are ordered in reverse progression.
 * 
 * @param arr the array to be checked
 * @param arrSize the size of the array
 * @return true if sorted
 * @return false if not sorted
 */
bool isArrIntSortedReverse (int arr[], int arrSize)
{
    int count = 0;
    for (int i=0; i<arrSize-1; i++)
    {
        if(arr[i]<arr[i+1]) count++;
    }
    return count<1;
}

void sortArray (int arr[], int len)
{
    int buffer = 0, leng = len-1, menorPos;
    for (int i=0; i<leng; i++)
    {
        menorPos = i;
        for(int j=i+1; j<len; j++)
        {
            if(arr[menorPos] > arr[j]){
                menorPos = j;
            }
        }
        buffer = arr[i];
        arr[i] = arr[menorPos];
        arr[menorPos] = buffer;
    }
}

void sortArrayReverse (int arr[], int len)
{
    int buffer = 0, leng = len-1, maiorPos;
    for (int i=0; i<leng; i++)
    {
        maiorPos = i;
        for(int j=i+1; j<len; j++)
        {
            if(arr[maiorPos] < arr[j]){
                maiorPos = j;
            }
        }
        buffer = arr[i];
        arr[i] = arr[maiorPos];
        arr[maiorPos] = buffer;
    }
}

/**
 * @brief Counts how many alphanumeric characters there are inside of a string
 * 
 * @param text the string in question
 * @return int - the amount of alphanumeric characters
 */
int countAplhaNumm(char *text)
{
    int leng = strlen(text),
        i = 0, count = 0;
    for (i=0; i<leng; i++)
    {
        if (isLetterr(text[i])||isNumberr(text[i])) {++count;}
    }
    return count;
}

/**
 * @brief Counts how many alphanumeric characters there are inside of each word in a string and prints them to the terminal
 * 
 * @param text the string in question
 * @return int - the amount of alphanumeric characters in total
 */
int countALphaNumSpcc(char *text)
{
    int i = 0, sqs = 0, count = 0, total = 0,
        leng = strlen(text);
    for (i=0; i<leng; ++i)
    {
        do
        {
            if(isNumberr(text[i])||isLetterr(text[i]))
            {
                ++count;
            }
            ++i;
        } while ((text[i]!=' ')&&(text[i]!='\0'));
        ++sqs;
        printf("%s%d%s%d%s\n", "A palavra ", sqs, " contem ", count, " letras ou numeros.");
        total += count; count = 0;
    }
    return total;
}

/**
 * @brief returns the factorial of an integer number
 * 
 * @param n the number in question. If a negative number, will be turned positive
 * @return int - n!
 */
int factorial(int n)
{
    int i = 2, total = 1;
    if (n<0) {n*=-1;}
    if (n!=0&&n!=1)
    {
        n++;
        for (i=2; i<n; i++) {total *= i;}
    }
    return total;
}

/**
 * @brief returns the nth number in fibonaccis sequence
 * 
 * @param n the index of the number
 * @return int - the nth number in fibonaccis sequence
 */
int fiboN (int n)
{
    int x = 0, y = 1, z = 0, i = 0;
    if(n==1){return 1;}
    else
    {
        for (i=0; i<n-1; i++)
    {
        z = x + y;
        x = y;
        y = z;
    }
    return z;
    }
}

/**
 * @brief reads a file, one integer per line, and saves the numbers in an array, returning the amount of
 * numbers saved in the array.
 * 
 * @param arq the file to be read
 * @param arr the array where the numbers go into
 * @param arrSize the size of the array
 * @return int returns the amount of numbers written
 */
int freadIntArr (FILE * arq, int arr[], int arrSize)
{
    int x = 0, i = 0;
    while (fscanf(arq, " %d", &x)==1&&i<arrSize)
    {
        arr[i]=x;
        i++;
    }
    return i;
}

/**
 * @brief Returns the average value of numbers in an array
 * @param arr the array to be read
 * @param n the size of the array
 * @return double the average value
 */
double avgArrInt(int arr[], int n)
{
    int sum = 0;
    for (int i=0; i<n; i++)
    {
        sum += arr[i];
    }
    return (double)sum/(double)n;
}

/**
 * @brief Checks if a target element can be found inside an array and returns where
 * @attention Be careful not to exceed the array's size
 * @param arr the array to be searched
 * @param target the element to be searched
 * @param startPos the first position to be checked
 * @param n how many positions should be checked
 * @return int -1 if the target was not found or the index of the target if it was found
 */
int searchArrayInt (int arr[], int target, int startPos, int n)
{
    int count = -1;
    if(startPos>=0&&n>0)
    {
        int found = 0;
        int* pos = &arr[0];
        while(count<n&&found<1)
        {
            if(*(pos+startPos)==target) found++;
            count++; pos++;
        }
        if(found==0) count = -1;
    }
    return count;
}

/**
 * @brief Counts how many times a target element can be found inside a parameter
 * @attention Be careful not to exceed the array's size
 * @param arr the array to be searched
 * @param target the element to be searched
 * @param startPos the first position to be checked
 * @param n how many positions should be checked
 * @return int the number of times the element was found
 */
int freqArrayInt (int arr[], int target, int startPos, int n)
{
    int* pos = &arr[0];
    int count = 0, i = 0;
    if(startPos>=0&&n>0)
    {
        while(i<n)
        {
            if(*(pos+startPos+i)==target) count++;
            i++;
        }
    }
    return count;
}

/**
 * @brief Adds the contents of two arrays and saves the result in the first one
 * @param s The size of the arrays
 * @param arr1 The first array
 * @param arr2 The second array
 */
void addArraysInt(int s, int arr1[], int arr2[])
{
    for(int i=0; i<s; i++)
    {
        arr1[i] += arr2[i];
    }
}

/**
 * @brief Adds the contents of two arrays after multiplying the second one by a value
 * and saves the result in the first one
 * @param s The size of the arrays
 * @param c The constant that multiplies the second array
 * @param arr1 The first array
 * @param arr2 The second array
 */
void addArraysConstInt(int s, int c, int arr1[], int arr2[])
{
    for(int i=0; i<s; i++)
    {
        arr1[i] += c*arr2[i];
    }
}

/**
 * @brief Returns the amount of dividers a number has
 * @param number The number in question
 * @return int The amount of dividers
 */
int amountDividers(int number)
{
    int amount = 0, x = 1;
    while (x<=number)
    {
        if(number%x==0) amount++;
        x++;
    }
    return amount;
}

/**
 * @brief Returns the amount of dividers a number has and saves each one of them in an array
 * @attention Be careful not to exceed the size of the array
 * @param number The number in question
 * @param arr The array where the dividers should be saved
 * @return int The amount of dividers
 */
int dividersInArray(int number, int arr[])
{
    int amount = 0, x = 1;
    while (x<=number)
    {
        if(number%x==0) 
        {
            arr[amount] = x;
            amount++;
        }
        x++;
    }
    return amount;
}

// https://www.instagram.com/renatomestremat/
