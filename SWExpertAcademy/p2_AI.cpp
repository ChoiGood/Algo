// No. 2 [사전 문제] AI의 반란 최후의 전쟁

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int 타입 데이터 2개를 관리할 수 있는 pair 클래스의 p객체
typedef pair<int,int> p;

// 좌측 index 선택 시  
vector<p> p12; 
vector<p> p13; 
vector<p> p21; 
vector<p> p23; 
vector<p> p31; 
vector<p> p32; 

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}


// 최적일 일 때 index에서 다른 곳으로 이동할 때 각각 pair에 그 값들 계산해서 저장시켜주기
void UpdatePair(int index, int name, vector<int> &A)
{
    if(index == 0) {
        p12.push_back(make_pair(name, abs(A[0] - A[1])));
        p13.push_back(make_pair(name, abs(A[0] - A[2])));
    }

    if(index == 1) {
        p21.push_back(make_pair(name, abs(A[1] - A[0])));
        p23.push_back(make_pair(name, abs(A[1] - A[2])));
    }

    if(index == 2) {
        p31.push_back(make_pair(name, abs(A[2] - A[0])));
        p32.push_back(make_pair(name, abs(A[2] - A[1])));
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
    cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

		int n;
    	cin >> n;
    
    	vector<int> Galuxy = {0, 0, 0};
        p12.clear();
        p13.clear();
        p21.clear();
        p23.clear();
        p31.clear();
        p32.clear();

    	vector<int> A(3);
        
        int greedtotal = 0;
    	// 입력받고 Greed로 값 가지고오고 저장해두기 (특수경우를 해결할수있게)
    	for(int i = 0; i < n; i++) {
        	int sum = 0;
        	int maxvalue = -1;
        	int maxindex;
        	for(int j = 0; j < 3; j++) {
            	cin >> A[j];
            	sum += A[j];
            	if(A[j] > maxvalue) {
                	maxvalue = A[j];
                	maxindex = j;
            	}
        	}
            // 최적일 일 때 index에서 다른 곳으로 이동할 때 각각 pair에 그 값들 계산해서 저장시켜주기
            UpdatePair(maxindex,i,A);
            
        	greedtotal += sum - maxvalue;
        	Galuxy[maxindex] += 1;
    	}

        //sort를 이용해서 정렬
        sort(p12.begin(), p12.end(), compare); 
        sort(p13.begin(), p13.end(), compare); 
        sort(p21.begin(), p21.end(), compare); 
        sort(p23.begin(), p23.end(), compare); 
        sort(p31.begin(), p31.end(), compare); 
        sort(p32.begin(), p32.end(), compare); 


        // ---------------------출력하기-------------------------------------------

        cout << "#" << test_case << " ";

        int excepttotal = 0;

        if(Galuxy[0] != 0 && Galuxy[1] != 0 && Galuxy[2] !=0) {
        	cout << greedtotal << endl;
    	}
        else if((Galuxy[0] + Galuxy[1] + Galuxy[2]) < 3) {
            cout << -1 << endl;;
        }
    	else { // 특수 경우
            // 두 부분이 0 일 때 ==> 한 쪽에서 최적값으로 이동 시키기 근데 걍 모든 케이스 보는게 맞겠다
            if(Galuxy[0] != 0 && Galuxy[1] == 0 && Galuxy[2] == 0) {
                if(p12[0].first != p13[0].first) {
                    excepttotal = greedtotal + p12[0].second + p13[0].second; 
                }
                else {
                    int temp1 = p12[0].second + p13[1].second;
                    int temp2 = p13[0].second + p12[1].second;

                    if(temp1 < temp2) {
                        excepttotal = greedtotal + temp1;
                    } else {
                        excepttotal = greedtotal + temp2;
                    }
                }
            }

            if(Galuxy[0] == 0 && Galuxy[1] != 0 && Galuxy[2] == 0) {
                if(p21[0].first != p23[0].first) {
                    excepttotal = greedtotal + p21[0].second + p23[0].second; 
                }
                else {
                    int temp1 = p21[0].second + p23[1].second;
                    int temp2 = p23[0].second + p21[1].second;

                    if(temp1 < temp2) {
                        excepttotal = greedtotal + temp1;
                    } else {
                        excepttotal = greedtotal + temp2;
                    }
                }
            }

            if(Galuxy[0] == 0 && Galuxy[1] == 0 && Galuxy[2] != 0) {
                if(p31[0].first != p32[0].first) {
                    excepttotal = greedtotal + p31[0].second + p32[0].second; 
                }
                else {
                    int temp1 = p31[0].second + p32[1].second;
                    int temp2 = p32[0].second + p31[1].second;

                    if(temp1 < temp2) {
                        excepttotal = greedtotal + temp1;
                    } else {
                        excepttotal = greedtotal + temp2;
                    }
                }
            }



            // 한 부분만 0 일 때 
            
            if(Galuxy[0] != 0 && Galuxy[1] != 0 && Galuxy[2] == 0) {
               
                // 둘다 2 이상.. ==> 걍 제일 최적으로 바뀌는 거 그대로 넣어줌
                if(p13[0].second < p23[0].second) { // 만약에 galuxy[0] == 1 이면 복잡해짐
                    if(Galuxy[0] != 1) {
                        excepttotal = greedtotal + p13[0].second;
                    } 
                    else {
                        // 땡겨서 이동 시킨거랑 걍 다른 곳에서 최적인거랑 비교하기
                        int temp1 = p13[0].second + p21[0].second;
                        int temp2 = p23[0].second;

                        if(temp1 < temp2) {
                            excepttotal = greedtotal + temp1;
                        } else {
                            excepttotal = greedtotal + temp2;
                        }

                    }     
                    
                } else {    // 만약에 galuxy[1] == 0 이면 복잡해짐
                    if(Galuxy[1] != 1) {
                        excepttotal = greedtotal + p23[0].second;
                    } 
                    else {
                        // 땡겨서 이동 시킨거랑 걍 다른 곳에서 최적인거랑 비교하기
                        int temp1 = p23[0].second + p12[0].second;
                        int temp2 = p13[0].second;

                        if(temp1 < temp2) {
                            excepttotal = greedtotal + temp1;
                        } else {
                            excepttotal = greedtotal + temp2;
                        }

                    }     
                }
            }

            if(Galuxy[0] != 0 && Galuxy[1] == 0 && Galuxy[2] != 0) {
               
                // 둘다 2 이상.. ==> 걍 제일 최적으로 바뀌는 거 그대로 넣어줌
                if(p12[0].second < p32[0].second) { // 만약에 galuxy[0] == 1 이면 복잡해짐
                    if(Galuxy[0] != 1) {
                        excepttotal = greedtotal + p12[0].second;
                    } 
                    else {
                        // 땡겨서 이동 시킨거랑 걍 다른 곳에서 최적인거랑 비교하기
                        int temp1 = p12[0].second + p31[0].second;
                        int temp2 = p32[0].second;

                        if(temp1 < temp2) {
                            excepttotal = greedtotal + temp1;
                        } else {
                            excepttotal = greedtotal + temp2;
                        }

                    }     
                    
                } else {    // 만약에 galuxy[1] == 0 이면 복잡해짐
                    if(Galuxy[2] != 1) {
                        excepttotal = greedtotal + p32[0].second;
                    } 
                    else {
                        // 땡겨서 이동 시킨거랑 걍 다른 곳에서 최적인거랑 비교하기
                        int temp1 = p32[0].second + p13[0].second;
                        int temp2 = p12[0].second;

                        if(temp1 < temp2) {
                            excepttotal = greedtotal + temp1;
                        } else {
                            excepttotal = greedtotal + temp2;
                        }

                    }     
                }
            }

            if(Galuxy[0] == 0 && Galuxy[1] != 0 && Galuxy[2] != 0) {
               
                // 둘다 2 이상.. ==> 걍 제일 최적으로 바뀌는 거 그대로 넣어줌
                if(p21[0].second < p31[0].second) { // 만약에 galuxy[0] == 1 이면 복잡해짐
                    if(Galuxy[1] != 1) {
                        excepttotal = greedtotal + p21[0].second;
                    } 
                    else {
                        // 땡겨서 이동 시킨거랑 걍 다른 곳에서 최적인거랑 비교하기
                        int temp1 = p21[0].second + p32[0].second;
                        int temp2 = p31[0].second;

                        if(temp1 < temp2) {
                            excepttotal = greedtotal + temp1;
                        } else {
                            excepttotal = greedtotal + temp2;
                        }

                    }     
                    
                } else {    // 만약에 galuxy[1] == 0 이면 복잡해짐
                    if(Galuxy[2] != 1) {
                        excepttotal = greedtotal + p31[0].second;
                    } 
                    else {
                        // 땡겨서 이동 시킨거랑 걍 다른 곳에서 최적인거랑 비교하기
                        int temp1 = p31[0].second + p23[0].second;
                        int temp2 = p21[0].second;

                        if(temp1 < temp2) {
                            excepttotal = greedtotal + temp1;
                        } else {
                            excepttotal = greedtotal + temp2;
                        }

                    }     
                }
            }

            cout << excepttotal << endl;
    	}
        
	

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}