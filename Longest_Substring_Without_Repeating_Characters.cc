/*
 * question: Longest Substring Without Repeating Characters
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3.
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

/*
 *
 * //primitive solution:346ms
 *
 * ����Ľⷨ��˳��ɨ��string����ÿ���ַ�����hash���У�Ȼ��鿴�Ƿ����ظ����ַ�������оͼ���һ����Ӵ���Ȼ������ұ��ظ��ַ�����һλ��������ɨ��
 *
 * ���⣺����ȥ�ظ�ɨ�裬ÿ�����hash��
 *
   int lengthOfLongestSubstring(string s) {
        int len = 0;
        int templen = 0;
        unordered_map<char,int> hash;
        for(int i = 0; i < s.size(); i++){
            if(hash.find(s[i]) == hash.end()){
                hash.insert({s[i] , i});
                templen++;
            }else{
                if(templen > len){
                    len = templen;
                }
                templen = 0;
                i = hash[s[i]];
                hash.clear();
            }
        }
        if(templen > len){
            len = templen;
        }
        return len;
    }
 */

/*
 * improvement:36ms
 *
     int lengthOfLongestSubstring(string s) {
        int len = 0;
        int pos = 0;
        unordered_map<char,int> hash;
        for(int i = 0; i < s.size(); i++){
            if(hash.find(s[i]) == hash.end()){
                hash.insert({s[i] , i});
                len = max(len,i-pos+1);  //���û���ظ�����len�������ӣ���+1����ָ��������i��ָ���ַ�
            }else{
                pos = max(pos,hash[s[i]]+1);
                len =max(len,i - pos + 1); //����ظ��������ж��ظ��ַ������pos��λ�ã�������pos��ֵ����Ϊ3���������1�����pos��������ظ��ַ����ұߣ��򱣳�pos���䣻��2�����pos
                hash[s[i]] = i;            //�����ظ���λ�ã�����ǰ �ƶ�һλ��Ŀ����ͳһ����ʹ��+1������3������ظ�λ��λ��pos�ұߣ���pos�ƶ����ظ�λ��֮ǰһλ��
            }							   //�����¸��ַ�����hash���е�ֵ����hash���е�ֵ������Ǹ��ַ��������Ѵ���Ĵ����ұߵ�λ��
        }
        return len;
    }
  */
