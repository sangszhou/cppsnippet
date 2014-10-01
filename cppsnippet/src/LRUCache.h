/*
 * LRUCache.h
 *
 *  Created on: 2014年10月1日
 *      Author: sangs
 */

#ifndef LRUCACHE_H_
#define LRUCACHE_H_

#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
	int key, value;
	Node *next, *pre;
	Node(int _key, int _value):key(_key), value(_value), next(NULL), pre(NULL){}
};
class LRUCache{
public:
	int capacity;
	int curSize;
	unordered_map<int, Node*> mp;
	Node *head;
    LRUCache(int capacity) {
		this->capacity = capacity;
		curSize = 0;
		head = nullptr;
    }

    int get(int key) {
      if(mp.find(key) == mp.end())
		  return -1;
	  int val = mp.find(key)->second->value;
	  set(key, val);
	  return val;
    }

    void set(int key, int value) {
		int ans = 0;
		if(mp.find(key) == mp.end())
			ans = -1;
		if(ans == -1) { // 新建一个 item
			if(curSize >= capacity) { // 已满, 需要删除一个 item
				if(capacity == 1) {
					mp.erase(mp.find(head->key));
					head->key = key;
					head->value = value;
					mp[key] = head;
					return;
				}else{
					// 模拟删除队尾元素
					Node *tail = head->pre;
					mp.erase(mp.find(tail->key));
					tail->key = key;
					tail->value = value;
					head = tail;
					mp[key] = head;
					return;
				}
			}
			// 未满, 添加元素
			if(curSize == 0) {
				head = new Node(key, value);
				head->pre = head;
				head->next = head;
				mp[key] = head;
				curSize++;
				return ;
			}else {
				Node *al = new Node(key, value);
				al->pre = head->pre;
				al->next = head;
				al->pre->next = al;
				head->pre = al;
				head = al;
				mp[key] = al;
				curSize++;
				return;
			}
		}else{
			if(head->key == key) {
			    head->value = value;
			    mp[key] = head;
			    return;
			}
			//cout << "here" << endl;
			Node *mid = mp.find(key)->second;
			mid->next->pre = mid->pre;
			mid->pre->next = mid->next;
			mid->value = value;
			mid->next = head;
			mid->pre = head->pre;
			head->pre = mid;
			mid->pre->next = mid;
			head = mid;
			mp[key] = mid;	// 修改 mp[key]
			return;
		}
	}
};


#endif /* LRUCACHE_H_ */
