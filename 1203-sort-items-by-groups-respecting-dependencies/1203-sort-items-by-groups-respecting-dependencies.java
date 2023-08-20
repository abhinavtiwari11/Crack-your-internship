
    class Solution {
    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
        Map<Integer, List<Integer>> m1 = new HashMap();
        Map<Integer, List<Integer>> m2 = new HashMap();
        Map<Integer, Queue<Integer>> m3 = new HashMap();
        int[] d1 = new int[m], d2 = new int[n], d3 = new int[n];
        for (int i = 0; i < n; i++)
        {
            if (group[i] == -1)
            {
                m1.put(i + m, new ArrayList());
                m2.put(i, new ArrayList());
            }
            else
            {
                d3[group[i]]++;
                m2.put(i, new ArrayList());
            }
        }
        for (int i = 0; i < m; i++) m1.put(i, new ArrayList());
        for (int i = 0; i < n; i++)
        {
            if (group[i] == -1)
            {
                for (int e : beforeItems.get(i))
                {
                    d2[i]++;
                    m2.get(e).add(i);
                }
            }
            else
            {
                for (int e : beforeItems.get(i))
                {
                    if (group[e] == group[i])
                    {
                        d2[i]++;
                        m2.get(e).add(i);
                    }
                    else
                    {
                        int idx = group[e] == -1 ? e + m : group[e];
                        d1[group[i]]++;
                        m1.get(idx).add(group[i]);
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) m3.put(i, new LinkedList());
        for (int i = 0; i < n; i++)
            if (group[i] != -1 && d2[i] == 0)
                m3.get(group[i]).offer(i);

        Queue<Integer> q1 = new LinkedList(), q2 = new LinkedList();
        for (int i = 0; i < m; i++) if (d1[i] == 0) q1.offer(i);
        for (int i = 0; i < n; i++) if (group[i] == -1 && d2[i] == 0) q2.offer(i);
        int[] ans = new int[n];
        int k = 0;
        while (!q1.isEmpty() || !q2.isEmpty())
        {
            while (!q2.isEmpty())
            {
                int cur = q2.poll();
                ans[k++] = cur;
                for (int next : m1.get(cur + m))
                {
                    d1[next]--;
                    if (d1[next] == 0) q1.offer(next);
                }
                for (int next : m2.get(cur))
                {
                    d2[next]--;
                    if (d2[next] == 0) q2.offer(next);
                }
            }
            while (!q1.isEmpty())
            {
                int cur = q1.poll();
                Queue<Integer> q3 = m3.get(cur);
                int k2 = k;
                while (!q3.isEmpty())
                {
                    int cur2 = q3.poll();
                    ans[k++] = cur2;
                    for (int next : m2.get(cur2))
                    {
                        d2[next]--;
                        if (d2[next] == 0)
                        {
                            if (group[next] == -1) q2.offer(next);
                            else q3.offer(next);
                        }
                    }
                }
                if (d3[cur] > k - k2) return new int[0];
                for (int next : m1.get(cur))
                {
                    d1[next]--;
                    if (d1[next] == 0) q1.offer(next);
                }
            }
        }

        return k == n ? ans : new int[0];
    }
}