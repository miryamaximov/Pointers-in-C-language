להלן קובץ `README.md` לפרויקט ב-**C** המדגים שימוש במצביעים בדרגות שונות (Pointers).

---

# **Pointer Levels Demonstration in C**  

## **תיאור**  
פרויקט זה ממחיש את השימוש במצביעים (**pointers**) בדרגות שונות:  
- מצביע פשוט לערך (Pointer to value)  
- מצביע למצביע (Pointer to pointer)  
- מצביע כפול למצביע (Double pointer)  
- הדגמה של שינוי ערכים דרך מצביעים והבנת ניהול זיכרון דינאמי.  

המטרה היא להמחיש כיצד פועלים מצביעים ולהבין את הקשר בין כתובות בזיכרון לערכים עצמם.

---

## **דרישות מערכת**  
- GCC (או כל קומפיילר תואם ל-C)  
- מערכת הפעלה Linux/Windows

---

## **התקנה והרצה**  

1. שכפל/י את הפרויקט:  
   ```bash
   git clone https://github.com/miryamaximov/Pointers-in-C-language.git
   cd ProjectPointers
   ```

2. הידור התוכנית:  
   ```bash
   gcc pointers.c -o pointers
   ```

3. הרצת התוכנית:  
   ```bash
   ./pointers
   ```

---

## **מבנה הפרויקט**  
```
pointers-demo/
│
├── pointers.c         # קובץ הקוד הראשי שמדגים את השימוש במצביעים
├── README.md          # תיעוד הפרויקט
```
 
## **רישיון**  
פרויקט זה מופץ תחת [MIT License](https://opensource.org/licenses/MIT).

---

בהצלחה! אם יש לך שאלות נוספות או אם את/ה זקוק/ה להבהרות, אני כאן לעזור 😊.
