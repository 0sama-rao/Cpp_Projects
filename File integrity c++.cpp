#include <iostream>
#include <cstdlib>
#include<fstream>

// The only function in the program, which is also the entry point
int main()
{
    // Declare all the variables we will need
    int c; // User's choice for the meuu
    int v; // The computed hash code value
    int r; // The hash code value in the file
    char filename[1000]; // The user inputted file name
    FILE* file; // The user file
    FILE* hash; // The hash file
    char buffer[1]; // A buffer for reading the user file

    cout<<"\t\t\t\t\tCHECKING FILE INTEGRITY\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t=======================\t\t\t\t\n";
    cout<<"Choose one from the following \n";
    cout<<"1.) Want to create a new file ? \n";
    cout<<"2.) Delete file ?\n";
    cout<<"3.) Want to edit a file ?\n";
    cin>>c;

    if (c == 1)
    {
        // Asking for the filename
        cout<<"Enter the data file Name : ";
        cin>>filename;

        // Write some sample text to the file
        file = fopen(filename, "w");
        fprintf(file, "this is simple text\n");
        fclose(file);

        // Read the file and compute the hash
        file = fopen(filename, "rb");
        v = 0;
        while (fread(buffer, 1, 1, file) != 0)
        {
            v = v * 23 + buffer[0];
        }
        fclose(file);

        // Write the hash to the file
        hash = fopen("index.info", "w");
        fprintf(hash, "%d", v);
        fclose(hash);
    }
    else if (c == 2)
    {
        // Asking for the filename
        cout<<"Enter the data file Name : ";
        cin>>filename;

        // Delete the files
        if (remove(filename) != 0)
        {
            cout<<"Error deleting hash\n";
        }
        if (remove("index.info") != 0)
        {
            cout<<"File is removed successfully\n";
        }
    }
    else if (c == 3)
    {
        // Asking for the filename
        printf("Enter the data file Name : ");
        scanf("%s", filename);

        // Read the file and compute the hash
        file = fopen(filename, "rb");
        v = 0;
        while (fread(buffer, 1, 1, file) != 0)
        {
            v = v * 23 + buffer[0];
        }
        fclose(file);

        // Read the hash
        hash = fopen("index.info", "r");
        fscanf(hash, "%d", &r);
        fclose(hash);

        if (v == r)
        {
            // If the hash matches
            printf("File not tampered\n");

            // Write some other sample text to the file
            file = fopen(filename, "w");
            fprintf(file, "this is another simple text\n");
            fclose(file);

            // Read the file and compute the hash
            file = fopen(filename, "rb");
            v = 0;
            while (fread(buffer, 1, 1, file) != 0)
            {
                v = v * 23 + buffer[0];
            }
            fclose(file);

            // Write the hash
            hash = fopen("index.info", "w");
            fprintf(hash, "%d", v);
            fclose(hash);
        }
        else
        {
            // If the hash does not match
            cout<<"File tampered\n";
        }
    }

    return 0;
}
