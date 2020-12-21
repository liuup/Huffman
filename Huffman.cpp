#include "Huffman.h"

// @brief 排序函数
bool sortByWeight(HuffNode * first, HuffNode * second)
{
    return first->weight < second->weight;
}

// @brief 构造函数
Huffman::Huffman()
{
    huffHeadPtr = nullptr; // 头节点指向空
}

// @brief 析构函数
Huffman::~Huffman()
{
    // TODO:递归删除哈弗曼树
    delete huffHeadPtr;    // 删除头节点
}

// @brief 输入Huffman映射表
void Huffman::getMap()
{
    char flag;  // 判断回车标志
    char input_char;    // 输入的字符
    int input_weight;  // 输入的权重

    while(true)
    {
        cin >> input_char;
        huffman_map.insert(pair<char, int>(input_char, -1));    // 插入字符

        if((flag = getchar()) == '\n')
            break;
    }

    for(iter = huffman_map.begin(); iter != huffman_map.end(); iter++)
    {
        cin >> input_weight;
        iter->second = input_weight;

        flag = getchar();   // 吸收逗号
    }
}

// @brief 打印Huffman映射表
void Huffman::showMap()
{
    for(iter = huffman_map.begin(); iter != huffman_map.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }
}

// @brief 编码
void Huffman::encodeElement()
{
    char flag;

    // input elements
    while(true)
    {
//        HuffNode * temp = (HuffNode *)malloc((sizeof(HuffNode)));
        HuffNode * temp = new HuffNode;

        cin >> temp->data;
        temp->weight = huffman_map[temp->data];
        temp->left = nullptr;
        temp->right = nullptr;

        huffnodes.push_back(temp);

        if((flag = getchar()) == '\n')
            break;
    }

    createTree();   // 构造huffman树



}

// @brief 解码
void Huffman::decodeElement()
{


}

// @brief 创建Huffman树
void Huffman::createTree()
{
    while(huffnodes.size() > 0)
    {
        // 按照weight从小到大进行排序
        sort(huffnodes.begin(), huffnodes.end(), sortByWeight);

        // 取出前两个节点
        if(huffnodes.size() == 1)
        {
            huffHeadPtr = huffnodes.at(0);
            huffnodes.erase(huffnodes.begin()); // 删除
        }
        else
        {
            // 取出前两个
            HuffNode * node_1 = huffnodes.at(0);
            HuffNode * node_2 = huffnodes.at(1);
            // 删除
            huffnodes.erase(huffnodes.begin());
            huffnodes.erase(huffnodes.begin());
            // 生成新的节点
            HuffNode * temp = new HuffNode;
            temp->weight = node_1->weight + node_2->weight;

            (node_1->weight < node_2->weight) ?
            (temp->left = node_1, temp->right = node_2) :
            (temp->left = node_2, temp->right = node_1);

            huffnodes.push_back(temp);
        }
    }
}