/*
There are N courses, labelled from 1 to N.

We are given relations[i] = [X, Y], representing a prerequisite relationship between course X and course Y: course X has to be studied before course Y.

In one semester you can study any number of courses as long as you have studied all the prerequisites for the course you are studying.

Return the minimum number of semesters needed to study all courses.  If there is no way to study all the courses, return -1.

Input: N = 3, relations = [[1,3],[2,3]]
Output: 2
Explanation: 
In the first semester, courses 1 and 2 are studied. In the second semester, course 3 is studied.

Input: N = 3, relations = [[1,2],[2,3],[3,1]]
Output: -1
Explanation: 
No course can be studied because they depend on each other.
*/

class Solution {
    public int minimumSemesters(int N, int[][] relations) {
        List<Integer>[] graph = new List[N+1];
        int[] inDegree = new int[N+1];
        for (int i = 1; i <= N; i++)
            graph[i] = new ArrayList<>();
        for (int[] edge : relations) {
            graph[edge[0]].add(edge[1]);
            inDegree[edge[1]]++;
        }
        
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i <= N; i++)
            if (inDegree[i] == 0)
                queue.offer(i);
        
        int studied = 0, semesters = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                int poll = queue.poll();
                studied++;
                for (int next : graph[poll]) {
                    if (--inDegree[next] == 0)
                        queue.offer(next);
                }
            }
            semesters++;
        }
        return studied == N ? semesters : -1;
    }
}
