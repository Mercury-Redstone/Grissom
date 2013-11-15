FOREIGN KEY(bruker_id)
        REFERENECES Bruker(bruker_id) 
        ON DELETE CASCADE 
    FOREIGN KEY(gruppe_id) 
        REFREENCES Gruppe(gruppe_id) 
        ON DELETE CASCADE
    );
 

