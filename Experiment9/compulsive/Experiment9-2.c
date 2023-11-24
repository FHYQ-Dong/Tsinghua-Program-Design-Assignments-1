#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_PIVOT -1 // in func select_pivot
#define INF_ANS 1
#define NO_ANS -1
#define SINGLE_ANS 0


void swap_line(double** a, double** b) { double* tmp = *a; *a = *b; *b = tmp; return; }
double dabs(double x) { return x>0 ? x : -x; }

int select_pivot(double** mat, double** b, int line_cnt, int cur_column) { // if no pivot, return -1
    
    double mx_abs = 0;
    int mx_row = cur_column;

    for (int i=cur_column; i<=line_cnt; ++i) {
        if (dabs(mat[i][cur_column]) > mx_abs) {
            mx_abs = dabs(mat[i][cur_column]);
            mx_row = i;
        }
    }

    if (mx_abs == 0) return NO_PIVOT;

    swap_line(&mat[cur_column], &mat[mx_row]);
    swap_line(&b[cur_column], &b[mx_row]);
    return cur_column;
}

void normalize_line(double* line, double pivot, int pivot_pos, int maxpos) {
    for (int i=pivot_pos; i<=maxpos; ++i) line[i] /= pivot;
    return;
}

void eliminate_line(double* target_line, double* pivot_line, int times, int maxpos) {
    for (int i=1; i<=maxpos; ++i) target_line[i] -= times * pivot_line[i];
    return;
}

int get_ans(double** mat, double** b, int mat_size, double* ans) {

    // Infinite answers
    if (b[mat_size][1]==0 && mat[mat_size][mat_size]==0) return INF_ANS;

    // No answer
    if (b[mat_size][1]!=0 && mat[mat_size][mat_size]==0) return NO_ANS;

    // Single answer
    ans[mat_size] = b[mat_size][1] / mat[mat_size][mat_size];
    for (int i=mat_size-1; i>=1; --i) {
        double sum = 0;
        for (int j=i+1; j<=mat_size; ++j) sum += mat[i][j] * ans[j];
        ans[i] = (b[i][1] - sum);   
    }
    return SINGLE_ANS;
}

void print_mat_a(double** mat, int mat_size) {
    printf("Mat A = \n");
    for (int i=1; i<=mat_size; ++i) {
        for (int j=1; j<=mat_size; ++j) printf("\t%.6lf", mat[i][j]);
        printf("\n");
    }
    return;
}
void print_mat_b(double** b, int mat_size) {
    printf("Mat B = \n");
    for (int i=1; i<=mat_size; ++i) printf("\t%.6lf", b[i][1]);
    printf("\n");
    return;
}

int main() {

    // init
    int mat_size;
    scanf("%d", &mat_size);
    double** mat = (double**)malloc(sizeof(double) * (mat_size+1));
    for (int i=0; i<=mat_size; ++i) mat[i] = (double*)malloc(sizeof(double) * (mat_size+1));
    for (int i=0; i<=mat_size; ++i) memset(mat[i], 0, sizeof(double) * (mat_size+1));
    double** b = (double**)malloc(sizeof(double) * (mat_size+1));
    for (int i=0; i<=mat_size; ++i) b[i] = (double*)malloc(sizeof(double) * 2);
    for (int i=0; i<=mat_size; ++i) memset(b[i], 0, sizeof(double) * 2);

    // input MAT_A and MAT_B
    for (int i=1; i<=mat_size; ++i) {
        for (int j=1; j<=mat_size; ++j) scanf("%lf", &mat[i][j]);
        scanf("%lf", &b[i][1]);
    }

    // print MAT_A and MAT_B
    print_mat_a(mat, mat_size);
    print_mat_b(b, mat_size);


    // Gauss Elimination
    for (int column_i=1; column_i<=mat_size; ++column_i) { // column i

        // select pivot
        int pivot_line = select_pivot(mat, b, mat_size, column_i); 
        if (pivot_line == NO_PIVOT) { // infinite answers
            printf("Infinite answers.\n");
            goto FREE;
        }

        // normalize pivot line
        double pivot = mat[pivot_line][column_i];
        normalize_line(mat[pivot_line], pivot, column_i, mat_size); // normalize pivot line (MAT A)
        normalize_line(b[pivot_line], pivot, 1, 1); // normalize pivot line (MAT B)

        // eliminate other lines
        for (int line_j=pivot_line+1; line_j<=mat_size; ++line_j) {
            double times = mat[line_j][column_i];
            eliminate_line(mat[line_j], mat[pivot_line], times, mat_size);
            eliminate_line(b[line_j], b[pivot_line], times, 1);
        }
    }
    
    // get answer
    double* ans = (double*)malloc(sizeof(double) * (mat_size+1));
    memset(ans, 0, sizeof(double) * (mat_size+1));

    int ans_type = get_ans(mat, b, mat_size, ans);
    if (ans_type == INF_ANS) printf("Infinite answers.\n");
    else if (ans_type == NO_ANS) printf("No answer.\n");
    else {
        printf("Answer:\n");
        for (int i=1; i<=mat_size; ++i) printf("x(%d) = %.6lf\n", i, ans[i]);
        printf("\n");
    }

    // free
    FREE:
    for (int i=0; i<=mat_size; ++i) free(mat[i]), free(b[i]);
    free(mat), free(b), free(ans);
    return 0;
}