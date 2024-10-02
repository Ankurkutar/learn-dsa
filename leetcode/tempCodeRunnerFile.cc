n()
{
    Solution solution;
    int rowIndex = 5;
    vector<int> result = solution.getRow(rowIndex);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}