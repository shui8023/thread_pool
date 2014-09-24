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
	
	public:
		thread_pool();
		~thread_pool();
	private:
		thread_pool(const thread_pool &);
		thread_pool & operator=(const thread_pool &);	
		int thread_count;
};

#endif //THREAD_POOL
