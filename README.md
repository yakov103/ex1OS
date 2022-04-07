# #תכנות מערכות הפעלה: מטלה 1

קישורי מידע שהשתמשנו בהם

https://stackoverflow.com/questions/2114377/copying-a-part-of-a-string-substring-in-c
https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/
https://www.geeksforgeeks.org/udp-server-client-implementation-c/
https://stackoverflow.com/questions/14150431/copying-a-file-in-c-with-fwrite
https://stackoverflow.com/questions/19099663/how-to-correctly-use-fork-exec-wait
https://www.geeksforgeeks.org/fork-system-call/
https://man7.org/linux/man-pages/man3/opendir.3.html
https://man7.org/linux/man-pages/man3/readdir.3.html
https://man7.org/linux/man-pages/man3/closedir.3.html
https://stackoverflow.com/questions/298510/how-to-get-the-current-directory-in-a-c-program


איך להריץ

```

git clone https://github.com/yakov103/ex1OS.git

cd ex1OS

make run

```

א. רוצו בלולאה הציגו prompt (לדוגמא yes master?) וקילטו קלט מהמשתמש. אם מתקבלת הפקודה EXIT - צאו מהshell שאתם כותבים. (5 נקודות)
![image](https://user-images.githubusercontent.com/62290677/162141413-ea78e196-6044-494b-b50f-02530dc66ca5.png)

ב. קראו את הספריה הנוכחית (בעזרת getcwd) והציגו אותה בprompt. הכניסו את ההוראות ששיניתם מסעיפים קודמים להערה. (5 נקודות)

![image](https://user-images.githubusercontent.com/62290677/162141537-7757c6ab-e535-4e67-a430-86047b995349.png)

ג. אם קיבלתם פקודה המתחילה ב ECHO הדפיסו לstandard output את הפלט המופיע אחרי ECHO (5 נקודות)
![image](https://user-images.githubusercontent.com/62290677/162141650-e30782c2-0a31-4a5b-80fb-592d14c333d9.png)

ד1. אם קיבלתם פקודה TCP PORT - יפתח לLocalhost קשר TCP (אתם בתפקיד הclient) והסטנדרט output יועתק לשם. (כלומר כל הפלט יצא לסוקט במקום לstdout הרגיל) - 15 נקודות
ד2. בנו server המציג את הפלט שמתקבל. - (10 נקודות)
נריץ בטרמינל חדש את הפקודה 
```
./server
```
ונקבל 
![image](https://user-images.githubusercontent.com/62290677/162141838-3dee6355-6916-434a-91ef-406509fe83ba.png)

ואז נחזור לטרמינל של המטלה ונכניס 

``` 
TCP PORT
```
![image](https://user-images.githubusercontent.com/62290677/162142299-a779c7ca-bb92-4590-a0b7-22e1ed2f6d6a.png)
נשלח הודעה לסרבר 
![image](https://user-images.githubusercontent.com/62290677/162142377-2178956d-2ad6-4e58-9561-5ebc8c692484.png)


ה. אם קיבלתם פקודה LOCAL - הסטנדרט output יעבור חזרה לטרמינל. כל socket אם קיים כזה (סעיף ד) יתנתק. - (5 נקודות)
![image](https://user-images.githubusercontent.com/62290677/162142558-577f5512-012c-4b00-a058-693a0a01ec14.png)

ו. אם קיבלתם פקודה DIR - הציגו את רשימת הקבצים בספריה הנוכחית לפלט הסטנדרטי.
![image](https://user-images.githubusercontent.com/62290677/162142669-97c4717d-95b5-4f96-a6df-f2024bd1e52d.png)

קראו את דפי הman של הפקודות האלה. - (15 נקודות)

https://man7.org/linux/man-pages/man3/opendir.3.html
https://man7.org/linux/man-pages/man3/readdir.3.html
https://man7.org/linux/man-pages/man3/closedir.3.html

ז. אם קיבלתם פקודה  CD - תצטרכו לשנות ספריה למחיצה שמגיעה כפרמטר אחרי CD (5 נקודות)
לצורך זה תצטרכו לקרוא לchdir. האם chdir היא פונקצית ספריה או קריאת מערכת? כתבו את התשובה בהערות (תעוד) 
תשובה:
// chdir function is declared
// inside this header
#include<unistd.h> 
זה פונקציה שנמצאת בתוך ספרייה אבל מכיוון שהיא משנה דברים במערכת כלומר משנה אז אפשר להגיד שהיא גם פונקציה מערכת

![image](https://user-images.githubusercontent.com/62290677/162154280-fb92404e-c931-4ee2-9312-e356f399396d.png)



ח. כל פקודה אחת שאתם מקבלים - הריצו אותה בעזרת system (5 נקודות)
ניתן לראות את פעולת הפקודה רק לפונקציות  DIR ECHO כי system יוצר תהליך חדש שבתוכו הוא משנה את הדברים , למשל chdir לא ניתן לראות את השינוי כי הוא משנה בתהליך הילד ולא באבא
![image](https://user-images.githubusercontent.com/62290677/162159997-a40a395e-0ce9-412b-a656-26a45f11271b.png)

![image](https://user-images.githubusercontent.com/62290677/162160054-6a62ddf4-45c0-459a-b919-7684ff3e3db6.png)



האם system היא פונקצית ספריה או קריאת מערכת? כיתבו את התשובה בהערות
תשובה:
   #include <stdlib.h>
   זה פונקציה שנמצאת בתוך ספרייה אבל מכיוון שהיא משנה דברים במערכת כלומר משנה אז אפשר להגיד שהיא גם פונקציה מערכת
   

ט. ממשו את הסעיף הקודם בעזרת fork, exec, wait ללא system. (15 נקודות)
הכניסו את ההוראות ששיניתם מסעיפים קודמים להערה.
![image](https://user-images.githubusercontent.com/62290677/162160255-e40f68fc-6aee-48ba-82eb-9e98e6a2163c.png)
![image](https://user-images.githubusercontent.com/62290677/162160315-4ea536bc-c64c-400f-acd1-553664d5d353.png)





י. אם מתקבלת הוראה COPY SRC DST - העתיקו את הקובץ המופיע בsource ל DST
בצעו זאת בעזרת fopen, fread, fwrite. (10 נקודות)
![image](https://user-images.githubusercontent.com/62290677/162161662-83f9ce46-7bc9-4c01-8b9c-c9ed99b5f121.png)


האם המימוש שלכם משתמש בקריאות מערכת או בפונקציית ספריה? כתבו את התשובות בהערה.
תשובה:
   #include <stdio.h>
   זה פונקציות שנמצאות בתוך ספרייה אבל מכיוון שהיא משנה דברים במערכת כלומר משנה אז אפשר להגיד שהיא גם פונקציה מערכת

י.א. אם מתקבלת הוראה DELETE FILENAME - מחקו את הקובץ המתקבל כFILENAME. עשו זאת בעזרת הוראת unlink.

![image](https://user-images.githubusercontent.com/62290677/162165914-56aa5260-a0a2-4df3-ab2b-0be7ce404f49.png)

האם המימוש שלכם משתמש בקריאות מערכת או בפונקצית ספריה? כתבו את התשובה בהערה (5 נקודות)
תשובה:
#include<unistd.h>     זה פונקציה שנמצאת בתוך ספרייה אבל מכיוון שהיא משנה דברים במערכת כלומר משנה אז אפשר להגיד שהיא גם פונקציה מערכת










