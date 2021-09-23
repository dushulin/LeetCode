public class test {
    public static int findNum(int[] arr, int n) {
        if (arr == null)
            return 0;
        int[] cand = new int[n];
        int idx = 0; // 记录当前cand数组中的元素个数。
        cand[idx++] = arr[0];
        int max = arr[0], i;
        for (i = 1; i < n; i++) {
            if (arr[i] >= max) {
                cand[idx++] = arr[i];
                max = arr[i];
            } else {
                while (idx > 0 && cand[idx - 1] > arr[i])
                    idx--;
            }
        }
        System.out.println("num: ");
        for (i = 0; i < idx; i++)
            System.out.print(cand[i]);
        System.out.print("\n");
        return idx;
    }

    public static void main(String args[]) {
        int[] arr = { 3, 1, 6, 4, 5, 7, 9, 8, 10, 14, 12 };
        // int[] arr = { 1, 2, 4, 5, 6, 7, 8, 9, 10, 3, 11 };
        int count = 0;
        count = findNum(arr, 11);
        System.out.println("count: " + count);

    }
}