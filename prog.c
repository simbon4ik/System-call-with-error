#include <stdio.h>
#include <sys/types.h> //Для pid_t
#include <signal.h>    //Для системного вызова kill
#include <errno.h>     //Для доступа к переменной errno и perror
#include <string.h>    //Для strerror (современная замена sys_errlist)

#define signal 0

int main(){
    errno = 0;                      //Обновляем переменную, если вдруг вызов пройдет удачно (в нашем случае невозможно, но в целом полезно)
    pid_t pid = -5;
    int result = kill(pid, signal); //Посылаем тестовый сигнал несуществующему процессу
    if (result == -1){
        printf("Error!\n");
        printf("The code error is %d\n", errno);     //Вывод с помощью переменной errno
        
        //printf("The problem is %s\n", sys_errlist[errno]);  //Вывод с помощью sys_errlist. Ошибка хранится по индексу errno. 
        //Сама функция устарела и удалена с С11. Безопаснее использовать strerror_s или strerror (сделал ниже), чем напрямую обращаться к sys_errlist
        //Тут же представил вариант, если делать по ТЗ. Стоит заметить, что для использования sys_errlist нужно добавить флаг компиляции --std=gnu11
        
        printf("The problem is: %s\n",strerror(errno));

        perror("I can repeat, the problem is");     //Вывод с помощью perror
    }
    return 0;
}
