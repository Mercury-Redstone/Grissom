CREATE TABLE Medlemskap(
    medlemskap_id INT(10) UNSIGNED NOT NULL, 
    bruker_id INT NOT NULL, 
    gruppe_id INT NOT NULL, 
    PRIMARY KEY(medlemskap_id),

    FOREIGN KEY(bruker_id)
        REFERENCES Bruker(bruker_id) 
        ON DELETE CASCADE,
    FOREIGN KEY(gruppe_id) 
        REFERENCES Gruppe(gruppe_id) 
        ON DELETE CASCADE
    );
 

