import openai

openai.api_key = "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"

def generate_prompts(activity_name):
    prompt = f"Describe a person performing {activity_name} in 15 words or less."
    response = openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        messages=[{"role": "user", "content": prompt}]
    )
    return response["choices"][0]["message"]["content"]

description = generate_prompts("jumping")
print("Generated description:", description)

