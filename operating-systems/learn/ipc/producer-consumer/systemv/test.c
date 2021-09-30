#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t  key = 75;         /* key to pass to semget() */
    int    semflg;      /* semflg to pass to semget() */
    int    nsems;       /* nsems to pass to semget() */
    int    semid;       /* return value from semget() */

    if ((semid = semget(key, nsems, semflg)) == -1) {
        perror("semget: semget failed");
        exit(1);
    } else
        printf("Success\n");
}
