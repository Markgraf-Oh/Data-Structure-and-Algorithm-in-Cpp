
namespace StringSearch
{
    std::vector<int> BruteForceSearch(const std::string & target_string, const std::string & key_string)
    {
        std::vector<int> search_result;
        for(int i = 0; i < target_string.size(); i++)
        {
            int j = 0;
            while((j < key_string.size()) &&
                  (target_string[i+j] == key_string[j])) j++;
            
            if(j == key_string.size()) search_result.push_back(i); 
        }

        return search_result;
    }

    std::vector<int> BoyerMooreSearch(const std::string & target_string, const std::string & key_string)
    {
        
        //배열을 안쓰고 벡터를 쓰는 건 초기화까지 한줄에 하려고
        std::vector<int> skip_table(CHAR_MAX - CHAR_MIN + 1, key_string.size());
        //skip_table 작성
        for(int i = 0; i < key_string.size() - 1; i++)
        {
            //해당 글자가 마지막 글자를 빼고 뒤에서 부터 몇번째에 처음 나타나는 지를 기록하면 됩니다.
            //루프는 앞에서 부터 돌고 있으니, 여러번 등장하는 문자의 경우 뒤쪽에 나타난 녀석이 자연스럽게 덮어씁니다.
            skip_table[int(key_string[i]) - CHAR_MIN] = key_string.size() - i - 1;
        }

        //search result
        std::vector<int> result_vector;
        //현재 보고 있는 target_string에서의 위치
        int target_loc = 0;
        //현재 비교하고 있는 key에서의 위치
        int key_loc;
        
        while(target_loc <= target_string.size() - key_string.size())
        {
            key_loc = key_string.size() - 1;
            while(key_loc >= 0 &&
                 (target_string[target_loc + key_loc] == key_string[key_loc]))
                  key_loc--;
            
            if(key_loc < 0)
            {
                result_vector.push_back(target_loc);
                target_loc += key_string.size();
            }else target_loc += skip_table[int(target_string[target_loc + key_loc]) - CHAR_MIN] - (key_string.size() - 1 - key_loc);
        }

        return result_vector;
    }

    void TestStringSearchAlgorithm(std::vector<int> (*searching_algo)(const std::string &/*target string*/, const std::string &/*key string*/),
                                   const std::string & algo_name,
                                   const std::string & target_string,
                                   const std::string & key_string,
                                   const std::string target_title)
    {
        namespace CR = std::chrono;
        CR::time_point<CR::high_resolution_clock> start_point = CR::high_resolution_clock::now();

        std::vector<int> search_result = searching_algo(target_string, key_string);

        CR::time_point<CR::high_resolution_clock> end_point = CR::high_resolution_clock::now();

        CR::duration<long long, std::nano> deltatime = end_point - start_point;

        std::cout<< algo_name << " found " << search_result.size() << " of " << key_string << " in " << target_title << std::endl;
        std::cout<< "run-time : " << CR::duration_cast<CR::microseconds>(deltatime).count() << Greek::mu << "s" <<std::endl;
        std::cout<< std::string(30, '-') << std::endl;
    }
}