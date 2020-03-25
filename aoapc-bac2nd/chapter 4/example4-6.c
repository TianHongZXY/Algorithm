//
// Created by TianHongZXY on 2020/3/21.
//
#include <stdio.h>
#include <string.h>
#define maxl 20
#define maxn 105
int n;
int removed[maxn];
int score[maxn][5];
char name[maxn][15];
char sid[maxn][15];
int cid[maxn];

void print_menu(){
    printf("1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit");
}

int rank(int i){
    int rk = 1;
    for(int j = 0; j < n; j++){
        if(score[j][4] > score[i][4]) rk++;
    }
    return rk;
}

void DQ(int isq){
    char s[maxl];
    for(;;){
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s", s);
        if(strcmp(s, "0") == 0) break;
        int r = 0;
        for(int i = 0; i < n; i++) if(!removed[i]){
            if(strcmp(sid[i], s) == 0 || strcmp(name[i], s) == 0){
                if(isq) printf("Rank %d Sid %s Cid %d Name %s Score %d %d %d %d Total %d Avg %.2f\n",
                        rank(i), sid[i], cid[i], name[i], score[i][0], score[i][1], score[i][2],
                        score[i][3], score[i][4], score[i][4] / 4.0);
                else{removed[i] = 1; r++;}
            }
        }
        if(!isq) printf("%d student(s) removed.\n", r);
    }
}

void add(){
    printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
    for(;;){
        scanf("%s", sid[n]);
        fflush(stdin);
        if (strcmp(sid[n], "0") == 0) break;
        scanf("%d %s %d %d %d %d", &cid[n], name[n], &score[n][0],
              &score[n][1], &score[n][2], &score[n][3]);
        score[n][4] = (score[n][0] + score[n][1] + score[n][2] + score[n][3]);
        n++;
        printf("Added!");
    }
}

void stat(){
    printf("Please enter class ID, 0 for the whole statistics.");
    int classid;
    char * subs[] = {"Chinese", "Mathematics", "English", "Programming"};
    scanf("%d", &classid);
    if(classid != 0){
        int num_student = 0;
        int num_pass_sub[4] = {0};
        double avg_sub[4] = {0.0};
        for(int i = 0; i < n; i++){
            if(cid[i] == classid){
                num_student++;
                for(int j = 0; j < 4; j++) {
                    avg_sub[j] += score[i][j];
                    if(score[i][j] > 60) num_pass_sub[j] += 1;
                }
            }
        }
        for(int i = 0; i < 4; i++){
            avg_sub[i] /= 1.0 * num_student;
            printf("%s\nAverage Score: %.2f\n", subs[i], avg_sub[i]);
            printf("Number of passed students: %d\n", num_pass_sub[i]);
            printf("Number of failed students: %d\n", num_student - num_pass_sub[i]);
        }
    }
    else{
        printf("Overall\n");
        int num_pass_sub[5] = {0};
        for(int i = 0; i < n; i++){
            int num_of_passed_sub = 0;
            for(int j = 0; j < 4; j++){
                if(score[i][j] > 60) num_of_passed_sub++;
            }
            for(int k = 1; k <= num_of_passed_sub; k++)
                num_pass_sub[k]++;
        }
        num_pass_sub[0] = n - num_pass_sub[1];
        printf("Number of students who passed all subjects: %d\n", num_pass_sub[4]);
        for(int i = 3; i >= 1; i--){
            printf("Number of students who passed %d or more subjects: %d\n", i, num_pass_sub[i]);
        }
        printf("Number of students who failed all subjects: %d\n", num_pass_sub[0]);
    }
}

int main(){
    for(;;){
        int choice;
        print_menu();
        scanf("%d", &choice);
        if(choice == 0) break;
        if(choice == 1) add();
        if(choice == 2) DQ(0);
        if(choice == 3) DQ(1);
        if(choice == 4) printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
        if(choice == 5) stat();
    }
    return 0;
}
