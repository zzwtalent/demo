#include "paramtool.h"

using namespace std;

class CParamPackUtil
{
public:
    CParamPackUtil()
    {
        m_c_param_splittoken = ',';
        m_c_field_splittoken = ':';
    }
    ~CParamPackUtil()
    {

    }
public:
    //设置分隔符
    bool SetSplitToken(char cSplitToken)
    {
        m_c_param_splittoken = cSplitToken;
    }

    //添加参数key-val对,如果key存在则覆盖
    bool AddParam(string strKey, string strVal)
    {
        map<string, string>::iterator iter_m_map_params = m_map_params.find(strKey);
        if (iter_m_map_params != m_map_params.end())
        {
            m_map_params[strKey] = strVal;
        }
        else
        {
            m_map_params.insert(make_pair(strKey, strVal));
        }
        return true;
    }

    //m_map_params中的所有参数使用token拼接,返回参数串
    bool GetParamsStr(string& strParams)
    {
        kdt_vchar64 szTmp;
        string strTmp;
        string strTmpParams;
        map<string, string>::iterator iter_m_map_params = m_map_params.find(strKey);
        for (; iter_m_map_params != m_map_params.end(); iter_m_map_params++)
        {
            KCPD_SNPRINTF_S(szTmp, sizeof(szTmp), sizeof(szTmp)-1 , "%s%c%s%c", iter_m_map_params->first.c_str, m_c_field_splittoken , iter_m_map_params->second.c_str(), m_c_param_splittoken);
            strTmp = szTmp;
            strTmpParams += strTmp;
        }
        //去掉最后一位

        strParams = strTmpParams.substr(0, strTmpParams.length()-1);
    }

    //解析参数，处理到m_map_params中
    bool ParseParams(string strParams)
    {
        int nStartPos = 0;
        kdt_vchar64 szParam[0] = 0;
        int nFieldStartPos = 0;
        kdt_vchar32 szKey[0] = 0;
        kdt_vchar32 szVal[0] = 0;
        while (strTokenize(strParams.c_str(), nStartPos, szParam, sizeof(szParam), m_c_param_splittoken))
        {
            
            if (strTokenize(szParam, nFieldStartPos, szKey, sizeof(szKey), m_c_field_splittoken) &&//取key
                strTokenize(szParam, nFieldStartPos, szVal, sizeof(szVal), m_c_field_splittoken))//取value
            {
                AddParam(szKey, szVal);
            }

        }
    }

private:

    inline bool strTokenize(const char *szToken, int& nStartPos, char *szDest, int nDestSize, char cDelimiter = ',')
    {
        const char *pTemp = strchr(szToken + nStartPos, cDelimiter);
        if (pTemp != NULL)
        {
            int nLen = (int)(pTemp - szToken - nStartPos);
            KCPD_STRNCPY_S(szDest, nDestSize, szToken + nStartPos, nLen);
            szDest[nLen++] = 0;
            nStartPos += nLen;
            return true;
        }
        if (szToken[nStartPos] == 0)
            return false;
        KCPD_STRCPY_S(szDest, nDestSize, szToken + nStartPos);
        nStartPos += (int)strlen(szToken + nStartPos);
        return true;
    }

public:
    map<string,string> m_map_params;
    char m_c_param_splittoken;
    char m_c_field_splittoken;

};

int main(int argc, char* argv[])
{
    cout<< "hello world!!" << endl;
}

