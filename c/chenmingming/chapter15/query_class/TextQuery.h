#ifndef TEXTQUERY_H //防止重复定义，名称大写
#define TEXTQUERY_H
#include<map>
#include<set>
#include<string>
#include<fstream>
#include<vector>

class TextQuery
{
public:
    typedef std::string::size_type str_size;
    typedef std::vector<std::string>::size_type line_no;
    void read_file(std::ifstream &is)   //定义函数，读取文件
    {
        store_file(is); //调用函数，把打开的文件流存入文件
        build_map();    //调用函数，生成map容器
    }
    std::string text_line(line_no) const;   //声明 行文本函数
    std::set<line_no> run_query(const std::string&) const;  //声明查询函数，返回行号集合set
    //每一个字符串所在行（返回set<>多个行号）
    line_no size() const;
private:
    void store_file(std::ifstream&);    //声明函数
    void build_map();                   //声明函数
    std::vector<std::string> lines_of_text; //定义每一行的文本作为一个元素存在vector里
    std::map<std::string, std::set<line_no> > word_map; 
    //把每个string和其行号<set> 做成map
    static std::string cleanup_str(const std::string&);
};
#endif