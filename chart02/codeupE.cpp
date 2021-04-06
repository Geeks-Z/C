#include <stdio.h>
int main(){
    int row, num, val;
    int res = 0;
    scanf("%d", &row);
    while(row--){
        scanf("%d", &num);
        while(num--){
            scanf("%d", &val);
            res += val;
        }
        printf("%d\n", res);
        res = 0;
    }
    return 0;
}
