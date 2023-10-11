
package main

import (
	"fmt"
	"sort"
	"strings"
)

func pathEncryption(path string) string {
	// var builder strings.Builder
	// for _, ele := range path {
	// 	if ele != '.' {
	// 		builder.WriteString(string(ele))
	// 	} else {
	// 		builder.WriteString(" ")
	// 	}

	// }
	// return builder.String()

	return strings.ReplaceAll(path, ".", " ")
}

// 724.寻找数组的中心下标
func findMiddleIndex(nums []int) int {
	var total int
	for _, ele := range nums {
		total += ele
	}

	var sum int
	for i, _ := range nums {
		if 2*sum+nums[i] == total {
			return i
		}

		sum += nums[i-1]
	}

	return -1
}

// 35.搜索插入位置
func searchInsert(nums []int, target int) int {
	left, right := 0, len(nums)-1

	for left <= right {
		mid := (left + right) >> 1 // 这个是向下取整的
		fmt.Printf("mid 分别为 %d\n", mid)

		if nums[mid] == target {
			return mid
		} else if nums[mid] > target {
			right = mid - 1
		} else if nums[mid] < target {
			left = mid + 1
		}
	}

	return left

	// for i, ele := range nums {
	// 	if ele >= target {
	// 		return i
	// 	}
	// }
	// return len(nums)
}

// LCR 074.合并区间
func merge(intervals [][]int) [][]int {
	if len(intervals) == 0 {
		return nil
	}

	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	merged := make([][]int, 0, len(intervals))

	for _, interval := range intervals {
		// 如果结果数组是空的 或者 当前区间和结果数组的最后一个区间无重叠，直接将当前区间添加到结果数组的后面
		if len(merged) == 0 || interval[0] > merged[len(merged)-1][1] {
			merged = append(merged, interval)
		} else {
			merged[len(merged)-1][1] = max(merged[len(merged)-1][1], interval[1])
		}
	}

	return merged
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

// 48. 旋转图像
func rotate(matrix [][]int) {
	// 方法1：使用辅助数组
	// 时间复杂度为O(n^2)，空间复杂度为O(n^2)。
	// n := len(matrix)
	// tem := make([][]int, n)
	// for i := range tem {
	// 	tem[i] = make([]int, n)
	// }

	// for i, row := range matrix {
	// 	for j, val := range row {
	// 		tem[j][n-1-i] = val
	// 	}
	// }

	// copy(matrix, tem)

	// 方法2：水平翻转 + 主对角线翻转
	n := len(matrix)

	// 水平翻转
	for i := 0; i < n/2; i++ {
		matrix[i], matrix[n-1-i] = matrix[n-1-i], matrix[i]
	}

	//主对角线翻转
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}
}

func main() {
	matrix := [][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}

	fmt.Println(len(matrix))
}
