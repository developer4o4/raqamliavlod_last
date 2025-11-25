import sqlite3
import shutil
import os

OLD_DB = "old.sqlite3"     # eski baza
NEW_DB = "db.sqlite3"     # yangi baza

OLD_TABLE = "news_news"    # eski jadval nomi
NEW_TABLE = "news_news"    # yangi jadval nomi

MEDIA_DIR = "media/news/"  # rasmlar papkasi (ixtiyoriy ko‘chirish)


def copy_news():
    old_conn = sqlite3.connect(OLD_DB)
    new_conn = sqlite3.connect(NEW_DB)

    old_cur = old_conn.cursor()
    new_cur = new_conn.cursor()

    # Eski DBdan ma'lumotlarni olish
    old_cur.execute(f"SELECT id, title, image, time, tg_url FROM {OLD_TABLE}")
    rows = old_cur.fetchall()

    print(f"{len(rows)} ta yangilik topildi. Ko'chirish boshlandi...\n")

    for row in rows:
        _, title, image, time, tg_url = row

        # ↳ Faylni ham ko‘chirib qo‘yish (agar mavjud bo'lsa)
        if image:
            old_path = f"old_media/{image}"
            new_path = f"new_media/{image}"

            os.makedirs(os.path.dirname(new_path), exist_ok=True)

            if os.path.exists(old_path):
                shutil.copy2(old_path, new_path)
                print(f"Image copied: {image}")
            else:
                print(f"Image NOT FOUND: {image}")

        # Yangi DBga yozish (ID avtomatik yaratiladi)
        new_cur.execute(
            f"""
            INSERT INTO {NEW_TABLE} (title, image, time, tg_url)
            VALUES (?, ?, ?, ?)
            """,
            (title, image, time, tg_url),
        )

    new_conn.commit()
    old_conn.close()
    new_conn.close()

    print("\nBarcha yangiliklar muvaffaqiyatli ko'chirildi!")


if __name__ == "__main__":
    copy_news()
