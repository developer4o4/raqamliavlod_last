import os
from aiogram import Bot, Dispatcher
from dotenv import load_dotenv
from pathlib import Path

load_dotenv(dotenv_path=Path(__file__).resolve().parent.parent / ".env")
API_TOKEN = os.getenv("TOKEN")

bot = Bot(token="7605171779:AAHT56CJwz6-JMI84imdpmkUWYJ7WhgloAI")
dp = Dispatcher()
