#读取配置文件
bool readConfigFile(int &a)
{
       string BEEP_I = "BEEP_I";
       ifstream configfile;
       string path = "./config.txt";
       configfile.open(path.c_str()); //打开文件
       if (!configfile.is_open()) {
              AR_LOG_FILE("can not open config file:%s\n ", path);
              return false;
       }
       char tmp[1000];
       configfile.getline(tmp, 1000); //每行读取前1000个字符，1000个应该足够了
       string line(tmp);
       size_t pos = line.find('=');//找到每行的“=”号位置，之前是key之后是value  
       if (pos == string::npos)
              return false;
       string tmpKey = line.substr(0, pos);//取=号之前  
       if (BEEP_I == tmpKey)
       {
              a = atoi(line.substr(pos + 1).c_str());//取=号之后  
       }
       return true;
}

#使用配置文件
int BEEP_I=0;
       bool error = readConfigFile(BEEP_I);
       if (0 == error)
       {
              AR_LOG_FILE("Read config file wrong!\n");
       }