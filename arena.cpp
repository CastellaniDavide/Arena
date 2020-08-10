#include <stdio.h>
#include <assert.h>



int main() {
    FILE *fr, *fw;
    int N, E, L, P, Q, i;
    char t;
    int morte = 0;
    int vivi = 0;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d %d %d", &N, &E, &L));
    int arr[N];
    for(int x = 0; x < N; x++){
        arr[x] = L;
    }

    for(i=0; i<E; i++) {
        assert(2 == fscanf(fr, "%d %c", &P, &t));
        if (t == 'f')
            assert(1 == fscanf(fr, "%d", &Q));
        else assert(t == 'e');

        if(t=='f'){
            arr[Q] -= 1;
        }
        else {
            arr[P] += 1;
            morte += 1;
        }

    }

    for(int x=0; x<N; x++){
        if(arr[x]>morte)
            vivi+=1;
    }

    fprintf(fw, "%d\n", vivi); // printing solution
    fclose(fr);
    fclose(fw);
    return 0;
}
