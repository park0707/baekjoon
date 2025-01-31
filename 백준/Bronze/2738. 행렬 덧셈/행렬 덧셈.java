import java.util.Scanner;
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException{
		Scanner scanner = new Scanner(System.in);
		
		int row = scanner.nextInt();
		int col = scanner.nextInt();
		
		int[][] arr1 = new int[row][col];
		int[][] arr2 = new int[row][col];
		int[][] arr3 = new int[row][col];
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				arr1[i][j] = scanner.nextInt();
			}
		}
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				arr2[i][j] = scanner.nextInt();
			}
		}
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				arr3[i][j] = arr1[i][j] + arr2[i][j];
			}
		}
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				System.out.print(arr3[i][j]+" ");
			}
			System.out.println();
		}
		
		
		scanner.close();
		
	}

}
