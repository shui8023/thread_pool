/*
 * =====================================================================================
 *
 *       Filename:  thread_pool.h
 *
 *    Description:  线程池的实现，使用信号量实现
 *
 *        Version:  1.0
 *        Created:  2014年09月24日 21时09分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */

#ifndef THREAD_POOL
#define THREAD_POOL

#include <iostream>
#include <pthread.h>
#include <vector>

using namespace std;

class thread_pool{
	public:
		typedef void *(*task)(void *);
		struct task_list{
			task task_fun;
			void *arg;
			struct task_list *next;
		};
		struct pthread_info{
			task_list *begin;
			task_list *end;
			int pthread_count;
			int max;
			int current_count;
			bool quit;
		};
		struct cont{
			pthread_mutex_t mutex;  //使用互斥锁
			pthread_cond_t cond; 	//条件变量
		};
	public:
		thread_pool();
		~thread_pool();
		void init_cond();
		void init_pthread(const int &);
		void destroy_cond();
		void *run_pthread();
		void add_task(task run_task, void *arg);
	private:
		cont cond_info;
		pthread_info pthread_info;
		vector<int> pids;
		thread_pool(const thread_pool &);
		thread_pool & operator=(const thread_pool &);	
};

#endif //THREAD_POOL
