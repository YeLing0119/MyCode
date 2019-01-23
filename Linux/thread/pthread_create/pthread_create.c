/*  这是一个演示创建线程的Demo
 *  
 *  phread_create( 
 *      pthread_t *thread,      //输出型参数，用于获取用户态线程ID
 *      const pthread_attr_t *attr,     //线程属性，通常设置为NULL
 *      void *(*start_routine) (void *),    //线程的入口函数
 *      void *arg   //传递给线程的参数
 *  ); 
 *
 *  功能: 创建一个线程
 *  返回值:
 *      成功: 0
 *      失败: 返回错误编号
 *          EAGAIN: 资源不足，无法创建/达到系统对线程的数量限制
 *          EINVAL: *attr 设置无效
 *          EPERM: 没有权限设置attr中指定的策略和参数
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* function_printf(void* data){
    printf("this is a thread\nget a pam is %lld\n", (long long int)data);
    return NULL;
}

int main(){
    pthread_t pthread;
    int ret = pthread_create(&pthread, NULL, &function_printf, (void*)1234);

    if(ret == 0){
        printf("creat pthread success\n");
    }else{
        printf("occured a problem errno is %d \n", ret);
    }

    printf("I am a main phread\n");

    sleep(5);

    return 0;
}
