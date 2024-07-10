#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    if(M == 1) {
        for(int i=1; i<=N; i++) {
            printf("%d\n", i);
        }
    }
    else if(M == 2) {
        for(int i=1; i<N; i++) {
            for(int j=i+1; j<=N; j++) {
                printf("%d %d\n", i, j);
            }
        }
    }
    else if(M == 3) {
        for(int i=1; i<N-1; i++) {
            for(int j=i+1; j<N; j++) {
                for(int k=j+1; k<=N; k++) {
                    printf("%d %d %d\n", i, j, k);
                }
            }
        }
    }
    else if(M == 4) {
        for(int i=1; i<N-2; i++) {
            for(int j=i+1; j<N-1; j++) {
                for(int k=j+1; k<N; k++) {
                    for(int l=k+1; l<=N; l++) {
                        printf("%d %d %d %d\n", i, j, k, l);
                    }
                }
            }
        }
    }
    else if(M == 5) {
        for(int i=1; i<N-3; i++) {
            for(int j=i+1; j<N-2; j++) {
                for(int k=j+1; k<N-1; k++) {
                    for(int l=k+1; l<N; l++) {
                        for(int m=l+1; m<=N; m++) {
                            printf("%d %d %d %d %d\n", i, j, k, l, m);
                        }
                    }
                }
            }
        }
    }
    else if(M == 6) {
        for(int i=1; i<N-4; i++) {
            for(int j=i+1; j<N-3; j++) {
                for(int k=j+1; k<N-2; k++) {
                    for(int l=k+1; l<N-1; l++) {
                        for(int m=l+1; m<N; m++) {
                            for(int n=m+1; n<=N; n++) {
                                printf("%d %d %d %d %d %d\n", i, j, k, l, m, n);
                            }
                        }
                    }
                }
            }
        }
    }
    else if(M == 7) {
        for(int i=1; i<N-5; i++) {
            for(int j=i+1; j<N-4; j++) {
                for(int k=j+1; k<N-3; k++) {
                    for(int l=k+1; l<N-2; l++) {
                        for(int m=l+1; m<N-1; m++) {
                            for(int n=m+1; n<N; n++) {
                                for(int o=n+1; o<=N; o++) {
                                    printf("%d %d %d %d %d %d %d\n", i, j, k, l, m, n, o);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if(M == 8) {
        for(int i=1; i<N-6; i++) {
            for(int j=i+1; j<N-5; j++) {
                for(int k=j+1; k<N-4; k++) {
                    for(int l=k+1; l<N-3; l++) {
                        for(int m=l+1; m<N-2; m++) {
                            for(int n=m+1; n<N-1; n++) {
                                for(int o=n+1; o<N; o++) {
                                    for(int p=o+1; p<=N; p++) {
                                        printf("%d %d %d %d %d %d %d %d\n", i, j, k, l, m, n, o, p);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    

    return 0;
}
