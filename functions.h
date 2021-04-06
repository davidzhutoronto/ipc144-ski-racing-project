/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)David Zhu				   dzhu34@myseneca.ca
   2)Raj Jaydeepsinh Kiransinh jkraj@myseneca.ca
   3)Sawan Harshadkumar Patel  shpatel18@myseneca.ca

   +--------------------------------------------------------+
   |                   FILE: main.c                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  S  U  M  M  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

void clearKeyboard(void);	//Function 1
int getInt(void);	//Function 2
int getIntInRange(int min, int max);	//Function 3
int menu(void);	//Function 4
void skiReportingSystem(void);	//Function 5
int getData(struct SkierInfo* info);	//Function 6
int sml(void);		//Function 7
void timeConversion(double startTime, double finishTime);	//Function 8
void sortSkier(struct SkierInfo info[], int size);	//Function 9
void ageGroup(int age);	//Function 10	
void topThree(struct SkierInfo info[], int size);	//Function 11
void all(struct SkierInfo info[], int size);	//Function 12
void lastThree(struct SkierInfo info[], int size);	//Function 13
void winner(struct SkierInfo info[], int size);		//Function 14

