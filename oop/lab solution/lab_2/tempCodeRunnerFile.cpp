   for (size_t i = 0; i < 2; i++)
    {
        cout << "** enter data for :" << i + 1 << endl;
        cout << "enter score for Team " << i + 1 << " : ";
        cin >> score;

        cout << "enter wickets for Team " << i + 1 << " : ";
        cin >> wickets;

        // Team T1;
        T[i].setScore(score);
        T[i].setWickets(wickets);
        cout << "Team " << i + 1 << " has scores: " << T[i].getScore() << " and wickets: " << T[i].getWickets() << endl;
    }