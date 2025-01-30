import openai

# ���� OpenAI API ��Կ
openai.api_key = "your_openai_api_key"

def generate_text(activity_name):
    prompt = f"Describe a person performing {activity_name} in 15 words or less."
    response = openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        messages=[{"role": "user", "content": prompt}]
    )
    return response["choices"][0]["message"]["content"]

# ʾ������
activity_description = generate_text("jumping")
print("Generated description:", activity_description)

