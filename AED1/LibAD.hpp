#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <ctime>
#include <cstdio>
#include <cstdbool>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>

/**
 * @brief Method that helps testing code, prints a message in the terminal that can be used to see up to when code ran.
 * 
 */
void flag()
{
	std::cout << "\n" << "FLAG" << "\n"; //Uses \n and not std::endl as not to affect the code around the flag
	getchar();
}

/**
 * @brief Prints out a line made of = symbols
 * 
 * @param length The length of the line
 */
void EQUALINE(int length) 
{
    for (int i = 0; i < length; i++) 
    {
        std::cout << "=";
    }
    std::cout << std::endl;
}

/**
 * @brief Prints a header menu in the terminal
 * 
 * @param a First bit of text to be print
 * @param b Seoond bit of text to be print
 * @return int - Wether the function suceeded in its task
 */
int Header(const char* a, const char* b) 
{
    int comprimentoTotal = strlen(a) + strlen(b) + 3;
    std::cout << "Matricula: 855947 Nome: ANTONIO_DRUMOND_COTA_DE_SOUSA\n\n";
    EQUALINE(comprimentoTotal);
    std::cout << a << " - " << b << std::endl;
    EQUALINE(comprimentoTotal);
    std::cout << std::endl;
    return EXIT_SUCCESS;
}

/**
 * @brief Function that returns a random number between two intervals
 * 
 * @param a The lower limit
 * @param b The upper limit
 * @param seed The seed of the random generation. Preferably use TIME(NULL), and multiply it by an integer after
 * every iteration when put in a loop.
 * @return int - The random number generated.
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
 * @brief Copies the content from an int* and puts it on another one, like strpcy but for ints
 * @param rece The receiving int*
 * @param giv The original int*
 * @param size The amount of characters to be copied 
 */
void intcpy(int* rece, int* giv, int size){
	for(int i=0; i<size; i++){
		rece[i] = giv[i];
	}
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
 * @brief Class used to work with arrays of integer numbers
 * 
 */
class ARRint
{
    public:
    int* arr;
    int leng;

    ARRint (int len){    //Constructor
        if(len>0){
            this->leng = len;
            arr = new int[leng];
        }
        else std::cerr << "ERRO: Dimensao invalida" << std::endl;
        
    }
    ~ARRint(){           //Destructor
        delete[] arr;
    }

    void print(){
        for(int i=0; i<leng; i++)
        {
            std::cout << *(arr+i) << " ";
        }
    }

    void fprint(std::ofstream& fil){
        for(int i=0; i<leng; i++)
        {
            fil << arr[i] << " ";
        }
    }

    bool fread(std::ifstream& fil){
        if(!fil.is_open()) {std::cout << "ERRO: Arquivo nao pode ser aberto. "; return false;}
        else if(leng<=0) {std::cout << "ERRO: Dimensoes do arranjo invalidas. "; return false;}
        else
        {
            for(int i=0; i<leng; i++){
                if(!(fil >> arr[i])){
                    std::cerr << "ERRO: Falha ao ler dados na posicao " << i;
                    return false;
                }
            }
            return true;
        }
    }

    int sumElements(int posA, int posB){
        int sum = 0;
        if(posA>leng || posB> leng) return 0;
        if(posA<=posB)
        {
            int exec = posB-posA+1;
            for(int i=0; i<exec; i++)
            {
                sum += *(arr+posA+i);
            }
        }
        else
        {
            int exec = posA-posB+1;
            for(int i=0; i<exec; i++)
            {
                sum += *(arr+posB+i);
            }
        }
        return sum;
    }

    double averageElements(int posA, int posB){
        return (sumElements(posA, posB) / abs(posB-posA+1));
    }

    bool areAllNegatives(){
        int i = 0;
        bool test = true;
        while (test==true && i<leng)
        {
            test = *(arr+i)<0 ? true : false;
            i++;
        }
        return test;
    }

    int search(int target, int posA, int posB){
        if(posA>leng || posB> leng) return -1;
        int i = 0;
        int found = false;
        if(posA<=posB)
        {
            int exec = posB-posA+1;
            while(i<exec && found == false){
                found = *(arr+posA+i) == target ? true : false;
                i++;
            }
            return found ? i+posA-1 : -1;
        }
        else
        {
            int exec = posA-posB+1;
            while(i<exec && found == false){
                found = *(arr+posB+i) == target ? true : false;
                i++;
            }
            return found ? i+posB-1 : -1;
        }
    }

    bool isSorted(){
        int i = 0;
        bool test = true;
        while(test==true && i<leng)
        {
            test = *(arr+i) <= *(arr+i+1) ? true : false;
            i++;
        }
        return test;
    }
    
    bool isSortedReverse(){
        int i = 0;
        bool test = true;
        while(test==true && i<leng)
        {
            test = *(arr+i) >= *(arr+i+1) ? true : false;
            i++;
        }
        return test;
    }

    void sort(){
        int buffer = 0, len = leng-1, smallPos;
        for (int i=0; i<len; i++)
        {
            smallPos = i;
            for (int j=i+1; j<leng; j++)
            {
                if(*(arr+smallPos) > arr[j]){
                    smallPos = j;
                }
            }
            buffer = *(arr+i);
            *(arr+i) = *(arr+smallPos);
            *(arr+smallPos) = buffer;
        }
    }

    void sortReverse(){
        int buffer = 0, len = leng-1, bigPos;
        for (int i=0; i<len; i++)
        {
            bigPos = i;
            for (int j=i+1; j<leng; j++)
            {
                if(arr[bigPos] < arr[j]){
                    bigPos = j;
                }
            }
            buffer = arr[i];
            arr[i] = arr[bigPos];
            arr[bigPos] = buffer;
        }
    }

    void scale(int c, int posA, int posB){
        if(!(posA>leng || posB> leng)){
            if(posA<=posB)
            {
                int exec = posB-posA+1;
                for(int i=0; i<exec; i++){
                    *(arr+posA+i) *= c;
                }
            }
            else
            {
                int exec = posA-posB+1;
                for(int i=0; i<exec; i++){
                    *(arr+posB+i) *= c;
                }
            }
        }
    }

	int* pushBack(int value){
		int* buffer = new int[leng+1];
		intcpy(buffer, arr, leng);
		leng++;
		delete arr;
		arr = buffer;
		arr[leng-1] = value;
		return arr;
	}

	int* popBack(){
		int* buffer = new int[leng-1];
		leng--;
		intcpy(buffer, arr, leng);
		delete arr;
		arr = buffer;
		return arr;
	}

	int* pushFront(int value){
		int* buffer = new int[leng+1];
		leng++;
		buffer[0] = value;
		int* temp = &buffer[1];
		intcpy(temp, arr, leng-1);
		delete arr;
		arr = buffer;
		return arr;
	}

	int* popFront(){
		int* buffer = new int[leng-1];
		leng--;
		int* temp = &arr[1];
		intcpy(buffer, temp, leng);
		delete arr;
		arr = buffer;
		return arr;
	}

	int* pushMid(int c){
		int* buffer = new int[leng+1];
		int half = leng/2;
		leng++;
		intcpy(buffer, arr, leng-1);
		buffer[half] = c; 
		int* temp1 = &arr[half];
		int* temp2 = &buffer[half+1];
		intcpy(temp2, temp1, leng-half);
		delete arr;
		arr = buffer;
		return arr;
	}

	int* popMid(){
		int* buffer = new int[leng-1];
		int half = leng/2;
		leng--;
		intcpy(buffer, arr, leng);
		int* temp1 = &arr[half+1];
		int* temp2 = &buffer[half];
		intcpy(temp2, temp1, leng-half);
		delete arr;
		arr = buffer;
		return arr;
	}

	int* insert(int x, int index){
		int* buffer = new int[leng+1];
		leng++;
		intcpy(buffer, arr, leng);
		buffer[index] = x;
		int* temp1 = &arr[index];
		int* temp2 = &buffer[index+1];
		intcpy(temp2, temp1, leng-index);
		delete arr;
		arr = buffer;
		return arr;
	}

	int* remove(int index){
		int* buffer = new int[leng-1];
		leng--;
		intcpy(buffer, arr, leng);
		int* temp1 = &arr[index+1];
		int* temp2 = &buffer[index];
		intcpy(temp2, temp1, leng-index);
		delete arr;
		arr = buffer;
		return arr;
	}

	int compare(ARRint* other){
		if(leng == other->leng){
			for(int i=0; i<leng; i++){
				if(arr[i]!=other->arr[i]) return arr[i] > other->arr[i] ? 1 : -1;
			}
			return 0;
		}
		else if(leng > other->leng){
			for(int i=0; i<other->leng; i++){
				if(arr[i]!=other->arr[i]) return arr[i] > other->arr[i] ? 1 : -1;
			}
			return arr[other->leng] > 0 ? 1 : -1;
		}
		else if(leng < other->leng){
			for(int i=0; i<leng; i++){
				if(arr[i]!=other->arr[i]) return arr[i] > other->arr[i] ? 1 : -1;
			}
			return other->arr[leng] > 0 ? -1 : 1;
		}
		else return 0;
	}

	int* concat(ARRint* other){
		int newSize = leng + other->leng;
		int* buffer = new int[newSize];
		int* temp = &buffer[leng];
		intcpy(buffer, arr, leng);
		intcpy(temp, other->arr, other->leng);
		leng = newSize;
		delete[] arr;
		arr = buffer;
		return arr;
	}

	int* searchPointer(int target){
		int i = 0;
		for(int i=0; i<leng; i++){
			if(arr[i]==target) return &arr[i];
		}
		return nullptr;
	}

	ARRint* subArray(int start, int size){
		if(start<0 || start>leng || size<0) return nullptr;
		ARRint* result = new ARRint(size);
		for(int i=0; i<size; i++){
			result->arr[i] = arr[start+i];
		}
		return result;
	}

	ARRint* merge(ARRint* other){
		ARRint* result = new ARRint(other->leng + leng);
		int i = 0,
			j = 0;
		while(i<leng){
			result->arr[i] = arr[i];
			i++;
		}
		while(j<other->leng){
			result->arr[i+j] = other->arr[j];
			j++;
		}
		return result;
	}

	ARRint* mergeUp(ARRint* other){
		ARRint* result = merge(other);
		result->sort();
		return result;
	}

};

/**
 * @brief Class used to work with matrixes of integer numbers
 * 
 */
class MATint
{
    public:
    int** mat;
    int lins;
    int cols;

    MATint(int lin, int col){   //Constructor
        if(lin>0 && col>0){
            this->lins = lin;
            this->cols = col;
            mat = new int*[lin];
            for(int i=0; i<lin; i++)
            {
                *(mat+i) = new int[col];
            }
        }
        else{
			mat = nullptr;
			std::cerr << "ERRO: Dimensao invalida" << std::endl;
		}
    }
    
    ~MATint(){                 //Destructor
		if(mat!=nullptr){
			for(int i=0; i<lins; i++)
				{
					delete[] *(mat+i);
				}
			delete[] mat;
		}
    }

    bool operator==(MATint& comp){
        if(this->lins!=comp.lins || this->cols!=comp.cols) return false;
        for (int i1=0; i1<lins; i1++)
            {
                for (int j1=0; j1<cols; j1++)
                {
                    if(this->mat[i1][j1] != comp.mat[i1][j1]) return false;
                }
            }
        return true;
    }

    void print(){
        for (int i1=0; i1<lins; i1++)
        {
            for (int j1=0; j1<cols; j1++)
            {
                std::cout << mat[i1][j1] << " ";
            }
            std::cout << std::endl;
        }
    }

    void fprint(std::ofstream& fil){
        for (int i1=0; i1<lins; i1++)
        {
            for (int j1=0; j1<cols; j1++)
            {
                fil << mat[i1][j1] << " ";
            }
            fil << std::endl;
        }
    }

    void fread(std::ifstream& fil){
        int buffer = 0;
        for (int i1=0; i1<lins; i1++)
        {
            for (int j1=0; j1<cols && !fil.eof(); j1++)
            {
                fil >> buffer;
                mat[i1][j1] = buffer;
            }
        }
    }

    int searchRows(int target){
        int i1 = -1;
        bool found = false;
        while(i1<lins && !found){
            i1++;
            for(int j1=0; j1<cols; j1++){
                if(mat[i1][j1] == target) found = true;
            }
        }
        return found ? i1 : -1;
    }

    int searchCols(int target){
        int i1 = 0, j1 = 0;
        bool found = false;
        for (i1=0; i1<lins && !found; i1++)
        {
            for (j1=0; j1<cols && !found; j1++)
            {
                if(mat[i1][j1] == target) found = true;
            }
        }
        return found ? j1-1 : -1;
    }

    void fillRand(int a, int b){
        int x = 1;        
        for (int i1=0; i1<lins; i1++)
        {
            for (int j1=0; j1<cols; j1++)
            {
                mat[i1][j1] = randInt(a, b, x);
                x*=13;
            }
        }
    }

    void fillCrescent(){
        int x = 1;
        for (int i1=0; i1<lins; i1++)
        {
            for (int j1=0; j1<cols; j1++)
            {
                mat[i1][j1] = x;
                x++;
            }
        }
    }

    void fillDecrescent(){
        int x = lins*cols;
        for (int i1=0; i1<lins; i1++)
        {
            for (int j1=0; j1<cols; j1++)
            {
                mat[i1][j1] = x;
                x--;
            }
        }
    }

    void scale(int c){
        for (int i1=0; i1<lins; i1++)
        {
            for (int j1=0; j1<cols; j1++)
            {
                mat[i1][j1] *= c;
            }
        }
    }

    void add(MATint* other){
        for (int i1=0; i1<lins; i1++)
        {
            for (int j1=0; j1<cols; j1++)
            {
                mat[i1][j1] += other->mat[i1][j1];
            }
        }
    }

    MATint* transpose(){
        MATint* result = new MATint(cols, lins);
        for (int i1=0; i1<lins; i1++)
        {
            for (int j1=0; j1<cols; j1++)
            {
                result->mat[j1][i1] = mat[i1][j1];
            }
        }
        return result;
    }

    bool addLineByProductOfSecond(int l1, int l2, int c){
        if(l1<lins&&l2<lins)
        {
            for(int i=0; i<cols; i++)
            {
                mat[l1][i] += mat[l2][i] * c;
            }
            return true;
        }
        else return false;
    }

    bool subtractLineByProductOfSecond(int l1, int l2, int c){
        if(l1<lins&&l2<lins)
        {
            for(int i=0; i<cols; i++)
            {
                mat[l1][i] -= mat[l2][i] * c;
            }
            return true;
        }
        else return false;
    }

    bool isIdentity(){
        bool id = true;
        if(lins!=cols) id = false;
        else{
            for (int i1=0; i1<lins && id; i1++)
            {
                for (int j1=0; j1<cols && id; j1++)
                {
                    if(i1==j1 && mat[i1][j1] != 1) id = false;
                    else if(i1!=j1 && mat[i1][j1] != 0) id = false;
                }
            }
        }
        return id;
    }
};

/**
 * @brief Class used to work with strings as an array of characters 
 * 
 */
class Astring
{
	public:
	char* string;
	int leng;
	char** splits;
	int nSplits;

	Astring(int size){
		string = new char[size+1];
		leng = size;
		splits = nullptr;
		nSplits = 0;
	}
	~Astring(){
		int i = 0;
		delete[] string;
		if(splits!=nullptr){
			while(splits[i]!=nullptr){
				delete[] splits[i];
				i++;
			}
			delete[] splits;
		}
	}

	int getInt(){
		int result = 0;
		for(int i=0; i<leng; i++){
			result += (int)((string[i]-48)*pow(10, leng-i-1));
		}
		return result;
	}
	
	double getDouble(){
		int i = 0;
		double result = 0.0;
		int comIndex = getCommaIndex(),
			amtLeft = leng-comIndex+2,
			j = comIndex-1;
		for(i=0; i<comIndex; i++){
			result += (double)((string[i]-48)*pow(10, j));
			j--;
		}
		j = 1;
		for(i=i+1; i<leng; i++){
			result += (double)((string[i]-48)/pow(10, j));
			j++;
		}
		return result;
	}

	bool getBool(){
		if(leng==4){
			if(string[0]=='t' && string[1]=='r' && string[2]=='u' && string[3]=='e') return true;
			else if(string[0]=='T' && string[1]=='R' && string[2]=='U' && string[3]=='E') return true;
			else return false;
		}
		else if(leng==1){
			if(string[0]=='t' || string[0]=='T' || string[0]=='1') return true;
			else return false;
		}
		else return false;
	}

	int search(std::string target){
		int i = 0;
		while (i<leng){
			if(string[i]==target[0])
				if(checkTarget(target, i)) return i;
			i++;
		}
		return -1;
	}

	char* makeUpper(){
		for(int i=0; i<leng; i++){
			if(isLowerr(string[i])) string[i]-=32;
		}
		return string;
	}

	char* makeLower(){
		for(int i=0; i<leng; i++){
			if(isUpperr(string[i])) string[i]+=32;
		}
		return string;
	}

	char* replace(char target, char subs){
		for(int i=0; i<leng; i++){
			if(string[i]==target) string[i]=subs;
		}
		return string;
	}

	char* encrypt(int k){
		int n = k%26;
		for(int i=0; i<leng; i++){
			string[i] = crypt(string[i], n);
		}
		return string;
	}

	char* decrypt(int k){
		int n = k%26;
		for(int i=0; i<leng; i++){
			string[i] = uncrypt(string[i], n);
		}
		return string;
	}

	int split(){
		int i = 0,
			j = 0;
		int count = 1;
		while(string[i]!='\0'){
			if(string[i]==' ') count++;
			i++;
		}
		splits = new char*[count];
		nSplits = count;
		count = 0;
		i = 0;
		while(string[i]!='\0' && count < nSplits){
			splits[count] = new char[100];
			j = 0;
			while(string[i]!=' ' && string[i]!='\0'){
				splits[count][j] = string[i];
				j++;
				i++;
			}
			splits[count][j] = '\0';
			count++;
			i++;
		}
		return nSplits;
	}

	int split(char sep){
		int i = 0,
			j = 0;
		int count = 1;
		while(string[i]!='\0'){
			if(string[i]==sep) count++;
			i++;
		}
		splits = new char*[count];
		nSplits = count;
		count = 0;
		i = 0;
		while(string[i]!='\0' && count < nSplits){
			splits[count] = new char[100];
			j = 0;
			while(string[i]!=sep && string[i]!='\0'){
				splits[count][j] = string[i];
				j++;
				i++;
			}
			splits[count][j] = '\0';
			count++;
			i++;
		}
		return nSplits;
	}
			
	int printSplits(){
		for(int i=0; i<nSplits; i++){
			std::cout << "\n" << splits[i];
		}
		return nSplits;
	}

	void print(){
		std::cout << string << "\n";
	}

	void reversePrint(){
		for(int i=leng; i>=0; i--){
			std::cout << string[i];
		}
		std::cout << "\n";
	}
	
	char* pushBack(char c){
		char* buffer = new char[leng+2];
		leng++;
		strcpy(buffer, string);
		delete string;
		string = buffer;
		string[leng-1] = c;
		return string;
	}

	char* popBack(){
		char* buffer = new char[leng];
		leng--;
		string[leng] = '\0';
		strcpy(buffer, string);
		delete string;
		string = buffer;
		return string;
	}

	char* pushFront(char c){
		char* buffer = new char[leng+2];
		leng++;
		buffer[0] = c;
		char* temp = &buffer[1];
		strcpy(temp, string);
		delete string;
		string = buffer;
		return string;
	}

	char* popFront(){
		char* buffer = new char[leng];
		leng--;
		char* temp = &string[1];
		strcpy(buffer, temp);
		delete string;
		string = buffer;
		return string;
	}

	char* pushMid(char c){
		char* buffer = new char[leng+2];
		int half = leng/2;
		leng++;
		strcpy(buffer, string);
		buffer[half] = c; 
		char* temp1 = &string[half];
		char* temp2 = &buffer[half+1];
		strcpy(temp2, temp1);
		delete string;
		string = buffer;
		return string;
	}

	char* popMid(){
		char* buffer = new char[leng+1];
		int half = leng/2;
		leng--;
		strcpy(buffer, string);
		char* temp1 = &string[half+1];
		char* temp2 = &buffer[half];
		strcpy(temp2, temp1);
		delete string;
		string = buffer;
		return string;
	}

	char* insert(char c, int index){
		char* buffer = new char[leng+2];
		leng++;
		strcpy(buffer, string);
		buffer[index] = c; 
		char* temp1 = &string[index];
		char* temp2 = &buffer[index+1];
		strcpy(temp2, temp1);
		delete string;
		string = buffer;
		return string;
	}

	char* remove(int index){
		char* buffer = new char[leng+1];
		leng--;
		strcpy(buffer, string);
		char* temp1 = &string[index+1];
		char* temp2 = &buffer[index];
		strcpy(temp2, temp1);
		delete string;
		string = buffer;
		return string;
	}

	char* searchptr(char target){
		for(int i=0; i<leng; i++)
			if(string[i]==target) return &string[i];
		return nullptr;
	}

	char* beforeptr(char target){
		int i = 0;
		bool found = false;
		for(i=0; i<leng && !found; i++)
			if(string[i]==target) found = true;
		if(found){
			string[i] = '\0';
			return string;
		}
		else return nullptr;
	}

	char* searchPrefix(char* target){
		int len = leng-strlen(target);
		bool found = true; 
		for(int i=0; i<len; i++){
			if(string[i]==' ' || i==0){
				int j = 0;
				while(target[j+1]!='\0'){
					if(target[j]!=string[i+j+1]){ 
						found = false;
						//j = strlen(target)-1;
					}
					j++;
				}
				if(found) return &string[i+1];
				else found = true;
			}
		}
		return nullptr;
	}
	char* searchSuffix(char* target){
		bool found = true;
		int i;
		for(i = strlen(target)-1; i<=leng; i++){
			if(string[i]==' ' || string[i]=='\0'){
				int j = 0;
				int control = strlen(target);
				for(j = 0; j < control; j++){
					if(string[i-j-1] != target[control-1-j]) {
						found = false; 
						j = control;
					}
				}
				if(found) return &string[i+1];
				else found = true;
			}
		}
		return nullptr;
	}

	private:

	int getCommaIndex(){
		int index = -1;
		for(int i=0; i<leng && index==-1; i++){
			if(string[i]==',' || string[i]=='.') index = i;
		}
		return index;
	}

	bool checkTarget(std::string target, int start){
		for(int i=0; i<target.size(); i++){
			if(string[start+i]!=target[i]) return false;
		}
		return true;
	}

	char crypt(char x, int n){
		if(isUpperr(x)) {
			x = (int)x;
			x+=abs(n);
			if(x>(int)'Z') x-=26;
			x = (char)x;
		}
		else if(isLowerr(x)) {
			x = (int)x;
			x+=abs(n)-32;
			if(x>(int)'Z') x-=26;
			x = (char)x+32;
		}
		return x;
	}

	char uncrypt(char x, int n){
		if(isUpperr(x)) {
			x = (int)x;
			x-=abs(n);
			if(x<(int)'A') x+=26;
			x = (char)x;
		}
		else if(isLowerr(x)) {
			x = (int)x;
			x-=abs(n);
			if(x<(int)'a') x+=26;
			x = (char)x;
		}
		return x;
	}
};
