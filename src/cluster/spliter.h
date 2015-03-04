#ifndef SSDB_CLUSTER_SPLITER_H
#define SSDB_CLUSTER_SPLITER_H

#include <stdint.h>
#include <string>
#include "key_range.h"

class SSDB;
class Node;

class Spliter{
public:
	Spliter(SSDB *cluster, Node *src_node, Node *dst_node);
	~Spliter();
	
	// 返回迁移的数据的字节数(估计), -1 表示出错; 0 表示已迁移完毕.
	int64_t move_some();
	int finish();

	SSDB *cluster;
	Node *src_node;
	Node *dst_node;

private:
	int init();

	int find_src_key_range_to_move(std::string *min_key, std::string *max_key);
	int64_t move_key_range(const std::string &min_key, const std::string &max_key);
	
	int copy_key(const std::string &key);
	
	int load_last_move_key();
	int save_last_move_key(const std::string &key);
	
	int set_src_kv_range(const std::string &min_key, const std::string &max_key);
	int set_dst_kv_range(const std::string &min_key, const std::string &max_key);
	int del_src_key(const std::string &key);

	std::string status_key;
	std::string last_move_key;
	KeyRange src_kv_range;
	KeyRange dst_kv_range;
};

#endif